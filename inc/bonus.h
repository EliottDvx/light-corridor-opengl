#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "scene.h"
#include "racket.h"

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
}Bonus;

typedef struct BonusList{
    Bonus* first;
}BonusList;

void initListBonus(BonusList* list);
void addBonus(BonusList *list, float z, Scene scene);
void drawBonus(Bonus *bonus);
void updateBonus(Scene *scene, BonusList *list);
void drawCube(Bonus bonus);