#include "corridor.h"
#include "3D_tools.h"

// void drawBase() {

// 	glColor3f((235./255.), (207./255.), (52./255.));

// 	glPushMatrix();
// 		glScalef(3.,3.,0.1);
// 		drawCircle();
// 	glPopMatrix();

// 	glPushMatrix();
// 		glScalef(2., 2., 10.);
// 		drawCone();
// 	glPopMatrix();
// }

void drawWall() {
	glColor3f(0.4,0.3,0.5);

	glTranslatef(0.,0.,30.);
	
	glScalef(100, 20, 0);
	glPushMatrix();

		glPushMatrix();
			glRotatef(80, 0, 1, 0);
			drawSquare();
		glPopMatrix();

		// glPushMatrix();
		// 	drawSquare();
		// glPopMatrix();

		// glPushMatrix();
		// 	drawSquare();
		// glPopMatrix();

		// glPushMatrix();
		// 	drawSquare();
		// glPopMatrix();

	glPopMatrix();
}

// void drawPan() {
// 	glColor3f((89./255.),(115./255.),0.);
// 	glPushMatrix();
// 		glScalef(3., 3., 5.);
// 		glTranslatef(0, 0, -1);
// 		drawCircle();
// 		glBegin(GL_LINES);
// 			glColor3f(1,0,0);
// 			glVertex3f(cos(2*M_PI/3), sin(2*M_PI/3), 0.);
// 			glVertex3f(0, 0, 1.);
// 			glVertex3f(cos(2*M_PI/3*2), sin(2*M_PI/3*2), 0.);
// 			glVertex3f(0, 0, 1.);
// 			glVertex3f(cos(2*M_PI/3*3), sin(2*M_PI/3*3), 0.);
// 			glVertex3f(0, 0, 1.);
// 		glEnd();
// 	glPopMatrix();
// }

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