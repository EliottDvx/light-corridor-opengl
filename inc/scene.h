#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

extern unsigned int WINDOW_WIDTH;
extern unsigned int WINDOW_HEIGHT;

#define MENU 0
#define RUNNING 1
#define OVER 2

typedef struct Scene{
    float height;
    float width;
    int playerMoving;
    float movingSpeed;
    int gameState;
}Scene;

Scene *createScene();