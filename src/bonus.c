#include "bonus.h"
#include "3D_tools.h"
#include "scene.h"
#include "racket.h"

void initListBonus(BonusList* list)
{
    list->first = NULL;
}

Bonus *createBonus(float z, Scene scene)
{
    Bonus *newBonus = (Bonus*)malloc(sizeof(Bonus));
    newBonus->z = z;
    newBonus->y = 0;
	
    newBonus->height = 2;
    newBonus->width = 2;

    newBonus->x = rand()%((int)scene.width/2 - (int)scene.width/4);

    return newBonus;
}

void destroyBonus(Bonus **ppBonus) {
    free(*ppBonus);
    *ppBonus = NULL;
}

void addBonus(BonusList *list, float z, Scene scene)
{
    Bonus *newBonus = createBonus(z, scene);
    newBonus->next = list->first;
    list->first = newBonus;
}

void retireBonus(BonusList* list, Bonus *bonus)
{
    Bonus *tempo = list->first;
    if(tempo!=NULL){
		if(tempo == bonus){
        	list->first = bonus->next;
        	destroyBonus(&bonus);
		}else{
			while(tempo->next != NULL && tempo->next != bonus){
				tempo = tempo->next;
			}
			if(tempo->next == bonus){
				tempo->next = bonus->next;
				destroyBonus(&bonus);
			}
		}
    }
}

void drawBonus(Bonus *bonus){
	bonus->colorR = -bonus->z/500+0.2;
    bonus->colorG = -bonus->z/500+0.4;
    bonus->colorB = -bonus->z/500+0.4;
    float R = bonus->colorR;
    float G = bonus->colorG;
    float B = bonus->colorB;
    glPushMatrix();
        glTranslatef(bonus->x, bonus->y, bonus->z);
        glRotatef(45,1,1,1);
        //glScalef(bonus->width, bonus->height, 0);
        drawCube(bonus->colorR, bonus->colorG, bonus->colorB);
    glPopMatrix();
}

void updateBonus(Scene *scene, BonusList *list){
	Bonus *bonus = list->first;
	glLineWidth(2.);

	for (bonus = list->first; bonus != NULL;) {
		drawBonus(bonus);
		if(bonus->z <= 0){
        	Bonus *nextBonus = bonus->next;
			retireBonus(list, bonus);
            if(rand()%2){
                addBonus(list, 90, *scene);
            }
			bonus = nextBonus;
		}
		else{
			if(scene->playerMoving){
				bonus->z -= scene->movingSpeed;
			}
			
			bonus = bonus->next;
		}
	}
}
