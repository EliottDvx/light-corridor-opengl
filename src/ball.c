#include "ball.h"
#include "3D_tools.h"

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

void updateBall(Ball *ball){
   ball->z+=.1;
}