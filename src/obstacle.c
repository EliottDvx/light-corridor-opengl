#include "obstacle.h"
#include "3D_tools.h"

void initListObst(ObstList* list)
{
    list->first = NULL;
}

Obst *createObst(float z)
{
    Obst *newObst = (Obst*)malloc(sizeof(Obst));
    newObst->z = z;
	newObst->x = rand()%5+1;
	newObst->y = rand()%2+1;
    return newObst;
}

void destroyObst(Obst *this) {
	free(this);
	this = NULL;
}

void addObst(ObstList *list,float z)
{
    Obst *newObst = createObst(z);
    newObst->next = list->first;
    list->first = newObst;
}

float retireFirstList(ObstList* list)
{
    Obst *tempo = list->first;
    if(tempo!=NULL){
        int value = tempo->z;
        list->first = tempo->next;
        destroyObst(tempo);
        return value;
    }else{
        return -1;
    }
}

void drawObstacle(float pas, ObstList *list){
	Obst *obst = list->first;
	pas = pas/50;
	glLineWidth(2.);
	glColor3f(0.2,0.2,0.4);
	glPushMatrix();

		obst->z -= pas;
		glPushMatrix();
			glTranslatef(0.,0.,obst->z);
			//glScalef(obst->x, obst->y, 0);
			drawSquare();
		glPopMatrix();

		while (obst->next != NULL)
    	{	
			obst = obst->next;
			obst->z -= pas;
			glPushMatrix();
				glTranslatef(-5.,0.,obst->z);
				//glScalef(obst->x, obst->y, 0);
				drawSquare();
			glPopMatrix();
    		
    	}
	glPopMatrix();
}