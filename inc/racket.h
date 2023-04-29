#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "obstacle.h"

typedef struct Racket{
    double racketSize;
    double x;
    double y;
}Racket;

Racket *createRacket();
void updateRacket(Racket *racket, double x, double y, int w, int h);
void drawRacket(Racket racket, int w, int h);
void getRacketCoords(GLFWwindow* window, double *x, double *y);

int chocObstacle(ObstList list, Racket racket);