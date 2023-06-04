#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "scene.h"
#include "racket.h"

typedef struct Obst{
    float height;
    float width;
    float z;
    float y;
    float x;
    struct Obst* next;
    float colorR;
    float colorG;
    float colorB;
}Obst;

typedef struct ObstList{
    Obst* first;
}ObstList;

void initListObst(ObstList* list);
void addObst(ObstList *list, float z, Scene scene, Racket *racket);
void drawObstacle(Obst *obst);
void updateObstacles(Scene *scene, ObstList *list, Racket *racket);

int racketObstacleCollision(ObstList *list, Racket racket);