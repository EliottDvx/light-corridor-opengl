#include "obstacle.h"
#include "3D_tools.h"

void drawObstacle(){
    glColor3f(0.2,0.2,0.4);
    glPushMatrix();
		glScalef(4, 5, 0);
		drawSquare();
	glPopMatrix();
}