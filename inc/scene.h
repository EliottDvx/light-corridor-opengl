#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

extern unsigned int WINDOW_WIDTH;
extern unsigned int WINDOW_HEIGHT;

typedef struct Scene{
    float height;
    float width;
    int playerMoving;
    float movingSpeed;
}Scene;

Scene *createScene();