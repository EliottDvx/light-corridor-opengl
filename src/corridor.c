#include "corridor.h"
#include "3D_tools.h"

void drawWall() {
	//glColor3f(0.33,0.37,0.46);
	glPushMatrix();
		
		for(int i = 0; i<20;i++){
			glPushMatrix();
				float j = i;
				float r = 0.33-(j/50);
				float g = 0.37-(j/50);
				float b = 0.46-(j/50);
				glColor3f(r, g, b);
				glTranslatef(5,0.,i*5.);
				glRotatef(90, 0, 1, 0);
				glScalef(5, 10, 0);
				drawSquare();
			glPopMatrix();
		}
		
		for(int i = 0; i<20;i++){
			glPushMatrix();
				float j = i;
				float r = 0.33-(j/50);
				float g = 0.37-(j/50);
				float b = 0.46-(j/50);
				glColor3f(r, g, b);
				glTranslatef(-5,0.,i*5.);
				glRotatef(90, 0, 1, 0);
				glScalef(5, 10, 0);
				drawSquare();
			glPopMatrix();
		}

		for(int i = 0; i<20;i++){
			glPushMatrix();
				float j = i;
				float r = 0.17-(j/50);
				float g = 0.19-(j/50);
				float b = 0.27-(j/50);
				glColor3f(r, g, b);
				glTranslatef(0.,-5./ratio,i*5.);
				glRotatef(-90, 1, 0, 0);
				glScalef(10, 5, 0);
				drawSquare();
			glPopMatrix();
		}

		for(int i = 0; i<20;i++){
			glPushMatrix();
				float j = i;
				float r = 0.17-(j/50);
				float g = 0.19-(j/50);
				float b = 0.27-(j/50);
				glColor3f(r, g, b);
				glTranslatef(0.,5./ratio,i*5.);
				glRotatef(-90, 1, 0, 0);
				glScalef(10, 5, 0);
				drawSquare();
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

void addLine(LineList *list,float z)
{
    Line *newLine = createLine(z);
    newLine->next = list->first;
    list->first = newLine;
}

void drawLinesWall(float pas, LineList *list) {
	Line *line = list->first;
	pas = pas/5;
	glColor3f(0.1,0.1,0.2);
	glLineWidth(2.);
	glPushMatrix();

		line->z -= pas;
		if(line->z <= 0){
			line->z = 100;
		}
		glPushMatrix();
			glTranslatef(0.,0.,line->z);
			glScalef(10.,10/ratio, 0.);
			drawLine();
		glPopMatrix();

		while (line->next != NULL)
    	{	
			line = line->next;
			line->z -= pas;
			if(line->z <= 0){
				line->z = 100;
			}
			glPushMatrix();
				glTranslatef(0.,0.,line->z);
				glScalef(10.,10/ratio, 0.);
				drawLine();
			glPopMatrix();
    		
    	}
	glPopMatrix();
}