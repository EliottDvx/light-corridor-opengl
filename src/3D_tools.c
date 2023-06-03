#include "3D_tools.h"

/* Camera parameters and functions */
float theta = 90.0f; // Angle between x axis and viewpoint
float phy = 0.0f; // Angle between z axis and viewpoint
float dist_zoom = 30.0f; // Distance between origin and viewpoint
float ratio = 16./9;

void setCamera() {
	gluLookAt(0.,0.,0.,
			  0.0,0.0,1.0,
			  0.0,1.0,0.0);
}

/* Convert degree to radians */
float toRad(float deg) {
	return deg*M_PI/180.0f;
}


void drawSquare() {
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(-0.5,-0.5,0.0);
		glVertex3f(0.5,-0.5,0.0);
		glVertex3f(0.5,0.5,0.0);
		glVertex3f(-0.5,0.5,0.0);
	glEnd();
}

void drawCircle() {
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0.0,0.0,0.0);
		float step_rad = 2*M_PI/(float)NB_SEG_CIRCLE;
		for(int i=0;i<=NB_SEG_CIRCLE;i++) {
			glVertex3f(cos(i*step_rad),sin(i*step_rad),0.0f);
		}
	glEnd();
}

void drawCone() {
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0.0,0.0,1.0);
		float step_rad = 2*M_PI/(float)NB_SEG_CIRCLE;
		for(int i=0;i<=NB_SEG_CIRCLE;i++) {
			glVertex3f(cos(i*step_rad),sin(i*step_rad),0.0f);
		}
	glEnd();
}

void drawSphere() {
	gluSphere(gluNewQuadric(),1.0,NB_SEG_CIRCLE,NB_SEG_CIRCLE);
}

void drawLine() {
	glBegin(GL_LINE_LOOP);
			glVertex3f(-0.5, 0.5, 0.);
			glVertex3f(0.5, 0.5, 0.);
			glVertex3f(0.5, -0.5, 0.);
			glVertex3f(-0.5, -0.5, 0.);
	glEnd();
}

void drawCube(float R, float G, float B){

	//devant
	glPushMatrix();
		glColor3f(R, G, B);
		glTranslatef(0,0,0.5);
		drawSquare();
	glPopMatrix();

	//derriere
	glPushMatrix();
		glColor3f(R-0.1, G-0.1, B-0.1);
		glTranslatef(0,0,-0.5);
		drawSquare();
	glPopMatrix();

	//dessus
	glPushMatrix();
		glColor3f(R+0.03, G+0.03, B+0.03);
		glTranslatef(0,0,0.5);
        glRotatef(90,1,0,0);
		drawSquare();
	glPopMatrix();

	//dessous
	glPushMatrix();
		glColor3f(R-0.05, G-0.05, B-0.05);
		glTranslatef(0,0,-0.5);
        glRotatef(90,1,0,0);
		drawSquare();
	glPopMatrix();

	//droite
	glPushMatrix();
		glColor3f(R-0.02, G-0.02, B-0.02);
		glTranslatef(0,0,0.5);
        glRotatef(90,0,1,0);
		drawSquare();
	glPopMatrix();

	//gauche
	glPushMatrix();
		glColor3f(R-0.02, G-0.02, B-0.02);
		glTranslatef(0,0,-0.5);
        glRotatef(90,0,1,0);
		drawSquare();
	glPopMatrix();
}

