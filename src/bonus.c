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
	
    newBonus->height = 1;
    newBonus->width = 1;

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
    
    glPushMatrix();
        glTranslatef(bonus->x, bonus->y, bonus->z);
        glRotatef(45,1,1,1);
        drawCube(*bonus);
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

void drawCube(Bonus bonus){

    float R = bonus.colorR;
    float G = bonus.colorG;
    float B = bonus.colorB;

    float W = (float)bonus.width/2.;

	//devant
	glPushMatrix();
		glColor3f(R, G, B);
		glTranslatef(0,0,W);
		drawSquare();
	glPopMatrix();

	//derriere
	glPushMatrix();
		glColor3f(R-0.1, G-0.1, B-0.1);
		glTranslatef(0,0,-W);
		drawSquare();
	glPopMatrix();

	//dessus
	glPushMatrix();
		glColor3f(R+0.03, G+0.03, B+0.03);
		glTranslatef(0,W,0);
        glRotatef(90,1,0,0);
		drawSquare();
	glPopMatrix();

	//dessous
	glPushMatrix();
		glColor3f(R-0.05, G-0.05, B-0.05);
		glTranslatef(0,-W,0);
        glRotatef(90,1,0,0);
		drawSquare();
	glPopMatrix();

	//droite
	glPushMatrix();
		glColor3f(R-0.02, G-0.02, B-0.02);
		glTranslatef(W,0,0);
        glRotatef(90,0,1,0);
		drawSquare();
	glPopMatrix();

	//gauche
	glPushMatrix();
		glColor3f(R-0.02, G-0.02, B-0.02);
		glTranslatef(-W,0,0);
        glRotatef(90,0,1,0);
		drawSquare();
	glPopMatrix();
}
