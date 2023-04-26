#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void drawFrame();
void drawWall();

typedef struct Line{
    float z;
    struct Line* next;
}Line;

typedef struct LineList{
    Line* first;
}LineList;

void initListLine(LineList* liste);
void addLine(LineList *list, float z);
void drawLinesWall(float pas, LineList *list);