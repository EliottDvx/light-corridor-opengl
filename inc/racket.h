#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void drawRacket(double x, double y, int w, int h);
void getRacketCoords(GLFWwindow* window, double *x, double *y);