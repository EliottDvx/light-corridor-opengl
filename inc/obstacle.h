#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct Obst{
    float z;
    int y;
    int x;
    struct Obst* next;
}Obst;

typedef struct ObstList{
    Obst* first;
}ObstList;

void initListObst(ObstList* list);
void addObst(ObstList *list, float z);
void drawObstacle(float pas, ObstList *list);