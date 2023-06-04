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
	
    newBonus->height = 1.5;
    newBonus->width = 1.5;

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

	float deg = glfwGetTime()*30;
    
    glPushMatrix();
        glTranslatef(bonus->x, bonus->y, bonus->z);
		glRotatef(deg,0,1,0);
		glRotatef(-45,1,1,1);
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
                addBonus(list, 100, *scene);
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

    float W = bonus.width;
    float H = bonus.height;

	//devant
	glPushMatrix();
		glColor4f(R, G, B, 0.75);
		glTranslatef(0,0,H/2.);
        glScalef(W,H,0);
		drawSquare();
	glPopMatrix();

	//derriere
	glPushMatrix();
		glColor4f(R-0.1, G-0.1, B-0.1, 0.75);
		glTranslatef(0,0,-H/2.);
        glScalef(W,H,0);
		drawSquare();
	glPopMatrix();

	//dessus
	glPushMatrix();
		glColor4f(R+0.05, G+0.05, B+0.05, 0.75);
		glTranslatef(0,H/2.,0);
        glRotatef(90,1,0,0);
        glScalef(W,H,0);
		drawSquare();
	glPopMatrix();

	//dessous
	glPushMatrix();
		glColor4f(R-0.08, G-0.08, B-0.08, 0.75);
		glTranslatef(0,-H/2.,0);
        glRotatef(90,1,0,0);
        glScalef(W,H,0);
		drawSquare();
	glPopMatrix();

	//droite
	glPushMatrix();
		glColor4f(R-0.05, G-0.05, B-0.05, 0.75);
		glTranslatef(W/2.,0,0);
        glRotatef(90,0,1,0);
        glScalef(H,H,0);
		drawSquare();
	glPopMatrix();

	//gauche
	glPushMatrix();
		glColor4f(R-0.04, G-0.04, B-0.04, 0.75);
		glTranslatef(-W/2.,0,0);
        glRotatef(90,0,1,0);
        glScalef(H,H,0);
		drawSquare();
	glPopMatrix();
}
