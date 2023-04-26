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
	newObst->width = rand()%20+1;
	newObst->height = rand()%10+1;
	newObst->x = rand()%10-5;
	newObst->y = rand()%6-3;
	newObst->colorR = -z/500+0.2;
	newObst->colorG = -z/500+0.2;
	newObst->colorB = -z/500+0.4;
    return newObst;
}

void destroyObst(Obst **ppObst) {
    free(*ppObst);
    *ppObst = NULL;
}

void addObst(ObstList *list,float z)
{
    Obst *newObst = createObst(z);
    newObst->next = list->first;
    list->first = newObst;
}

void retireObst(ObstList* list, Obst *obst)
{
    Obst *tempo = list->first;
    if(tempo!=NULL){
		if(tempo == obst){
        	list->first = obst->next;
        	destroyObst(&obst);
		}else{
			while(tempo->next != NULL && tempo->next != obst){
				tempo = tempo->next;
			}
			if(tempo->next == obst){
				tempo->next = obst->next;
				destroyObst(&obst);
			}
		}
    }
}

void drawObstacle(float pas, ObstList *list){
	Obst *obst = list->first;
	glLineWidth(2.);

	glPushMatrix();
	for (obst = list->first; obst != NULL;) {
		obst->z -= pas/5;
		obst->colorR = -obst->z/500+0.2;
		obst->colorG = -obst->z/500+0.2;
		obst->colorB = -obst->z/500+0.4;
		glPushMatrix();
			glColor3f(obst->colorR,obst->colorG,obst->colorB);
			glTranslatef(obst->x, obst->y, obst->z);
			glScalef(obst->width, obst->height, 0);
			drawSquare();
		glPopMatrix();
		
		if(obst->z <= 0){
        Obst *nextObst = obst->next;
        retireObst(list, obst);
        addObst(list, 100);
        obst = nextObst;
    }
    else{
        obst = obst->next;
    }
	}
	glPopMatrix();
}