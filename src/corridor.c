#include "corridor.h"
#include "3D_tools.h"

void drawWall() {
	glColor3f(0.33,0.37,0.46);
	
	glPushMatrix();
		
		glPushMatrix();
			glTranslatef(5,0.,0.);
			glRotatef(90, 0, 1, 0);
			glScalef(50, 10, 0);
			drawSquare();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-5,0.,0.);
			glRotatef(-90, 0, 1, 0);
			glScalef(50, 10, 0);
		drawSquare();
		glPopMatrix();

		glColor3f(.17,.19,.27);

		glPushMatrix();
			glTranslatef(0.,-5./ratio,0.);
			glRotatef(-90, 1, 0, 0);
			glScalef(10, 50, 0);
		 	drawSquare();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.,5./ratio,0.);
			glRotatef(90, 1, 0, 0);
			glScalef(10, 50, 0);
			drawSquare();
		glPopMatrix();

	glPopMatrix();
}

void drawLinesWall(float pas) {
	glColor3f(0,0,0);
	glPushMatrix();
	glTranslatef(0.,0.,-pas);
		for(int i=0; i<5; i++){
			glPushMatrix();
				glTranslatef(0.,0.,i);
				drawLine();
			glPopMatrix();
		}
	glPopMatrix();
}


void drawFrame() {
    glBegin(GL_LINES);

	glColor3f(1, 0, 0);
	glVertex3f(-.5, 0, 0);
	glVertex3f(.5, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0, -.5, 0);
	glVertex3f(0, .5, 0);

    glColor3f(0, 0, 1);
	glVertex3f(0, 0, -.5);
	glVertex3f(0, 0, .5);

	glEnd();
}