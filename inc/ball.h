#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "scene.h"
#include "racket.h"

typedef struct Ball{
    double size;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
    double maxSpeed;
}Ball;

Ball *createBall();

void drawBall();

void updateBall(Scene *scene, Ball *ball);

void ballRacketCollision(Ball *ball, Racket *racket);