#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "obstacle.h"

static const unsigned int WINDOW_WIDTH = 1280;
static const unsigned int WINDOW_HEIGHT = 720;

typedef struct Racket{
    double racketSize;
    double x;
    double y;
}Racket;

Racket *createRacket();
void updateRacket(Racket *racket, double x, double y, double glWallWidth, double glWallHeight);
void drawRacket(Racket racket);
void getRacketCoords(GLFWwindow* window, double *x, double *y);

int chocObstacle(ObstList list, Racket racket);