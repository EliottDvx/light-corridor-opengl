#include "ball.h"
#include "3D_tools.h"


void drawBall(){
    glColor3f(0.6,0.6,0.8);
	glPushMatrix();
        glScalef(0.5, 0.5, 0.5);
		drawSphere();
    glPopMatrix();
}