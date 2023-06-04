#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "scene.h"
#include "racket.h"
#include "ball.h"

typedef enum{
    SETSTICKY,
    LIVEUP
} BonusType;

typedef struct Bonus{
    float height;
    float width;
    float z;
    int y;
    int x;
    struct Bonus* next;
    float colorR;
    float colorG;
    float colorB;
    BonusType type;
}Bonus;

typedef struct BonusList{
    Bonus* first;
}BonusList;

Bonus *createBonus(float z, Scene scene, BonusType type);
void initListBonus(BonusList* list);
void racketBonusCollision(BonusList *list, Racket racket, Scene	*scene, Ball *ball);
void addBonus(BonusList *list, float z, Scene scene, BonusType type);
void retireBonus(BonusList *list, Bonus *bonus);
void drawBonus(Bonus *bonus);
void updateBonus(Scene *scene, BonusList *list);
void drawCube(Bonus bonus);