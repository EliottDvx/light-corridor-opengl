#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "scene.h"

typedef struct Racket{
    double racketSize;
    double x;
    double y;
}Racket;

Racket *createRacket();
void updateRacket(Racket *racket, double x, double y, Scene scene);
void drawRacket(Racket racket, BallState state);
void getRacketCoords(GLFWwindow* window, double *x, double *y);