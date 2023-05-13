#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "scene.h"

typedef struct Ball{
    double size;
    double x;
    double y;
    double z;
}Ball;

Ball *createBall();

void drawBall();

void updateBall(Scene *scene, Ball *ball);