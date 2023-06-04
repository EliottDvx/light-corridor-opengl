#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

extern unsigned int WINDOW_WIDTH;
extern unsigned int WINDOW_HEIGHT;

typedef enum {
    MENU, RUNNING, OVER
} GameState;

typedef struct Scene{
    float height;
    float width;
    int playerMoving;
    float movingSpeed;
    GameState gameState;
    int lives;
}Scene;

Scene *createScene();

void drawLives(Scene *scene);