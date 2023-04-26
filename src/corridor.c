#include "corridor.h"
#include "3D_tools.h"

void drawWall() {
	glColor3f(0.33,0.37,0.46);
	glPushMatrix();
		
		glPushMatrix();
			glTranslatef(5,0.,0.);
			glRotatef(90, 0, 1, 0);
			glScalef(100, 10, 0);
			drawSquare();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-5,0.,0.);
			glRotatef(-90, 0, 1, 0);
			glScalef(100, 10, 0);
		drawSquare();
		glPopMatrix();

		glColor3f(.17,.19,.27);

		glPushMatrix();
			glTranslatef(0.,-5./ratio,0.);
			glRotatef(-90, 1, 0, 0);
			glScalef(10, 100, 0);
		 	drawSquare();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.,5./ratio,0.);
			glRotatef(90, 1, 0, 0);
			glScalef(10, 100, 0);
			drawSquare();
		glPopMatrix();

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

void initListLine(LineList* list)
{
    list->first = NULL;
}

Line *createLine(float z)
{
    Line *newLine = (Line*)malloc(sizeof(Line));
    newLine->z = z;
    return newLine;
}

// void destroyLine(Line *this) {
// 	free(this);
// 	this = NULL;
// }

void addLine(LineList *list,float z)
{
    Line *newLine = createLine(z);
    newLine->next = list->first;
    list->first = newLine;
}

// float retireFirstList(LineList* list)
// {
//     Line *tempo = list->first;
//     if(tempo!=NULL){
//         int valeur = tempo->z;
//         list->first = tempo->next;
//         destroyLine(tempo);
//         return valeur;
//     }else{
//         return -1;
//     }
// }

void drawLinesWall(float pas, LineList list) {
	Line line = *list.first;
	pas = pas/50;
	glColor3f(0.1,0.1,0.2);
	glLineWidth(2.);
	glPushMatrix();

		glPushMatrix();
			glTranslatef(0.,0.,line.z-pas);
			drawLine();
		glPopMatrix();

		while (line.next != NULL)
    	{	
			line = *line.next;
			glPushMatrix();
				glTranslatef(0.,0.,line.z-pas);
				drawLine();
			glPopMatrix();
    		
    	}
	glPopMatrix();
}