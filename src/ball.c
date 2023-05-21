#include "ball.h"
#include "3D_tools.h"
#include "scene.h"
#include "racket.h"
#include <math.h>

Ball *createBall(){
    Ball *ball = (Ball*)malloc(sizeof(Ball));
    ball->size = .5;
    ball->x = 0;
    ball->y = 0;
    ball->z = 20;
    ball->vx = 0;
    ball->vy = 0;
    ball->vz = -.3;
    ball->maxSpeed = .3;
    return ball;
}

void drawBall(Ball ball){
    glColor3f(0.6,0.6,0.8);
	glPushMatrix();
        glTranslatef(ball.x, ball.y, ball.z);
        glScalef(ball.size, ball.size, ball.size);
		drawSphere();
    glPopMatrix();
}

void updateBall(Scene *scene, Ball *ball){
    ball->x += ball->vx;
    ball->y += ball->vy;
    ball->z += ball->vz;

    if(scene->playerMoving){
        ball->z -= scene->movingSpeed;
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

        double newVx = relativePosX / 4;
        double newVy = relativePosY / 4;

        double normalisation = sqrt(pow(newVx, 2) + pow(newVy, 2) + pow(ball->vz, 2));

        double factor = ball->maxSpeed / normalisation;

        ball->vx = newVx * factor;
        ball->vy = newVy * factor;
        ball->vz = -ball->vz * factor;
    }
}