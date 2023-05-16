#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "scene.h"

void drawFrame();
void drawWall(Scene scene);

typedef struct Line{
    float z;
    struct Line* next;
}Line;

typedef struct LineList{
    Line* first;
}LineList;

void initListLine(LineList* liste);
void addLine(LineList *list, float z);
void drawLinesWall(Scene *scene, LineList *list);