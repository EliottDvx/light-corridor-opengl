#include "ball.h"
#include "3D_tools.h"
#include "scene.h"
#include "racket.h"
#include <math.h>
#include "obstacle.h"

Ball *createBall(){
    Ball *ball = (Ball*)malloc(sizeof(Ball));
    ball->size = .5;
    ball->x = 0;
    ball->y = 0;
    ball->z = 10;
    ball->maxSpeed = .3; // Vitesse de la balle
    ball->vx = 0;
    ball->vy = 0;
    ball->vz = -ball->maxSpeed;
    ball->state = STICKY;
    return ball;
    ball->xStickyOffset = 0;
    ball->yStickyOffset = 0;
}

void drawBall(Ball ball){
    float R = -ball.z/80+0.6;
	float G = -ball.z/80+0.6;
	float B = -ball.z/60+0.8;
    glColor3f(R,G,B);
	glPushMatrix();
        glTranslatef(ball.x, ball.y, ball.z);
        glScalef(ball.size, ball.size, ball.size);
		drawSphere();
    glPopMatrix();
}

void updateBall(Scene *scene, Ball *ball, Racket *racket){
    if(ball->state == MOVING || ball->state == MOVINGSTICKY){
        ball->x += ball->vx;
        ball->y += ball->vy;
        ball->z += ball->vz;

        if(scene->playerMoving){
            ball->z -= scene->movingSpeed;
        }
    }
    else if(ball->state == STICKY){
        ball->x = racket->x + ball->xStickyOffset;
        ball->y = racket->y + ball->yStickyOffset;
        ball->z = ball->size;
    }
}

void ballRacketCollision(Ball *ball, Racket *racket){
    if(ball->z <= ball->size
    && ball->x >= racket->x - racket->racketSize/2 - ball->size/2
    && ball->y >= racket->y - racket->racketSize/2 - ball->size/2
    && ball->x <= racket->x + racket->racketSize/2 + ball->size/2
    && ball->y <= racket->y + racket->racketSize/2 + ball->size/2){

        float relativePosX = (ball->x - racket->x) / (racket->racketSize/2);
        float relativePosY = (ball->y - racket->y) / (racket->racketSize/2);

        if(ball->state == MOVINGSTICKY){
            ball->xStickyOffset = relativePosX;
            ball->yStickyOffset = relativePosY;
            ball->state = STICKY;
        }

        int ponderation = 6;
        double newVx = relativePosX / ponderation;
        double newVy = relativePosY / ponderation;
        double newVz = ball->maxSpeed;

        double normalisation = sqrt(pow(newVx, 2) + pow(newVy, 2) + pow(newVz, 2));

        double factor = ball->maxSpeed / normalisation;

        ball->vx = newVx * factor;
        ball->vy = newVy * factor;
        ball->vz = newVz * factor;
    }
}

void ballCorridorCollision(Ball *ball, Scene *scene){
    if(ball->x >= scene->width/2 - ball->size){
        ball->vx = -fabs(ball->vx);
    }
    if(ball->x <= -scene->width/2 + ball->size){
        ball->vx = fabs(ball->vx);
    }
    if(ball->y >= scene->height/2 - ball->size){
        ball->vy = -fabs(ball->vy);
    }
    if(ball->y <= -scene->height/2 + ball->size){
        ball->vy = fabs(ball->vy);
    }
}

void ballObstacleCollision(Ball *ball, ObstList *list){
    Obst *obst = list->first;
    float wallThicknessFront = .2; // Evite que la balle traverse le mur de face
    float wallThicknessBack = .9; // Evite que la balle traverse le mur de dos

    for (obst = list->first; obst != NULL;) {
        if(ball->z + ball->size/2 >= obst->z - wallThicknessFront && ball->z - ball->size/2 <= obst->z + wallThicknessBack/2){
            if(ball->x >= obst->x - obst->width/2 - ball->size &&
               ball->x <= obst->x + obst->width/2 + ball->size &&
               ball->y >= obst->y - obst->height/2 - ball->size &&
               ball->y <= obst->y + obst->height/2 + ball->size){

                if(ball->z < obst->z){
                    ball->vz = -fabs(ball->vz);
                }
                else{
                    ball->vz = fabs(ball->vz);
                }
            }
        }

        obst = obst->next;
    }
}

void ballVoidCollision(Ball *ball, Scene* scene){
    if(ball->z <= 0 - ball->size){
        ball->xStickyOffset = 0;
        ball->yStickyOffset = 0;
        ball->state = STICKY;
        scene->lives--;
        if(scene->lives <= 0){
            scene->gameState = OVER;
        }
    }
}

void ballEndWallCollision(Ball *ball, EndWall endWall, Scene *scene){
    if(ball->z >= endWall.z){
        if(endWall.winScreen){
            scene->gameState = ENDING;
        }
        ball->vz = -fabs(ball->vz);
}
    }

    