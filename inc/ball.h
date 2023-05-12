#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct Ball{
    double size;
    double x;
    double y;
    double z;
}Ball;

Ball *createBall();

void drawBall();