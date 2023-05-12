#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "scene.h"

typedef struct Obst{
    int height;
    int width;
    float z;
    int y;
    int x;
    struct Obst* next;
    float colorR;
    float colorG;
    float colorB;
}Obst;

typedef struct ObstList{
    Obst* first;
}ObstList;

void initListObst(ObstList* list);
void addObst(ObstList *list, float z);
void drawObstacle(Scene *scene, ObstList *list);