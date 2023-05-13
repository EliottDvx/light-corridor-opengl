#include "ball.h"
#include "3D_tools.h"
#include "scene.h"

Ball *createBall(){
    Ball *ball = (Ball*)malloc(sizeof(Ball));
    ball->size = .5;
    ball->x = 0;
    ball->y = 0;
    ball->z = 0;
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

    //Gérer les déplacements de la balle ici
    ball->z += .2;

    if(scene->playerMoving){
        ball->z -= scene->movingSpeed;
    }
}