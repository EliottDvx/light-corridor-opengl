#include "obstacle.h"
#include "3D_tools.h"
#include "scene.h"
#include "racket.h"

void initListObst(ObstList* list)
{
    list->first = NULL;
}

Obst *createObst(float z, Scene scene, Racket *racket)
{
    Obst *newObst = (Obst*)malloc(sizeof(Obst));
    newObst->z = z;

	int posX = rand()%3;
	int posY = rand()%3;

	int maxWidth = (int)scene.width-racket->racketSize;
	int minWidth = (int)scene.width/3;
	int maxHeight = (int)scene.height-racket->racketSize;
	int minHeight = (int)scene.height/3;
	
	 switch(posX){
		case 1:
			newObst->height = scene.height;
			newObst->width = minWidth + rand()%(maxWidth + 1 - minWidth);
			newObst->x = scene.width/2-newObst->width/2;
			break;
		case 2:
			newObst->height = scene.height;
			newObst->width = minWidth + rand()%(maxWidth + 1 - minWidth);
			newObst->x = -(scene.width/2-newObst->width/2);
			break;
		default :
			newObst->x = 0;
	}

	switch(posY){
		case 1:
			newObst->width = scene.width;
			newObst->height = minHeight + rand()%(maxHeight + 1 - minHeight);
			newObst->y = scene.height/2-newObst->height/2;;
			break;
		case 2:
			newObst->width = scene.width;
			newObst->height = minHeight + rand()%(maxHeight + 1 - minHeight);
			newObst->y = -(scene.height/2-newObst->height/2);
			break;
		default :
			newObst->y = 0;
	}
	
	if(posX == 0 && posY == 0){
		newObst->width = minWidth + rand()%((int)scene.width + 1 - minWidth);
		newObst->height = minHeight + rand()%((int)scene.height + 1 - minHeight);
	}
	
	while(newObst->width>=scene.width-racket->racketSize*2 &&
	newObst->height>=scene.height-racket->racketSize*2){
		int choice = rand()%2;
		if(choice){
			newObst->width = minWidth + rand()%(maxWidth + 1 - minWidth);
		}else{
			newObst->height = minHeight + rand()%(maxHeight + 1 - minHeight);
		}
	}

	newObst->colorR = -z/500+0.2;
	newObst->colorG = -z/500+0.2;
	newObst->colorB = -z/500+0.4;
    return newObst;
}

void destroyObst(Obst **ppObst) {
    free(*ppObst);
    *ppObst = NULL;
}

void addObst(ObstList *list, float z, Scene scene, Racket *racket)
{
    Obst *newObst = createObst(z, scene, racket);
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

void drawObstacle(Scene *scene, ObstList *list, Racket *racket){
	Obst *obst = list->first;
	glLineWidth(2.);

	glPushMatrix();
	for (obst = list->first; obst != NULL;) {
		if(scene->playerMoving){
			obst->z -= scene->movingSpeed;
		}
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
			addObst(list, 100, *scene, racket);
			obst = nextObst;
		}
		else{
			obst = obst->next;
		}
	}
	glPopMatrix();
}

int chocObstacle(ObstList *list, Racket racket){
    Obst* obst;
    float size = racket.racketSize/2.;
    
    for (obst = list->first; obst != NULL;obst = obst->next) {
        
		if(obst->z <= 0.5){
            if(racket.x - size < obst->x + obst->width/2. &&
                racket.x + size > obst->x - obst->width/2. &&
                racket.y - size < obst->y + obst->height/2. &&
                racket.y + size > obst->y - obst->height/2.){
                    return 0;
            }
        }
	}
    return 1;
}