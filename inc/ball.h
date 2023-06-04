#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "scene.h"
#include "racket.h"
#include "obstacle.h"

typedef enum {
    STICKY,
    MOVING
} BallState;
typedef struct Ball{
    double size;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
    double maxSpeed;
    BallState state;
}Ball;

Ball *createBall();

void drawBall();

void updateBall(Scene *scene, Ball *ball, Racket *racket);

void ballRacketCollision(Ball *ball, Racket *racket);

void ballCorridorCollision(Ball *ball, Scene *scene);

void ballObstacleCollision(Ball *ball, ObstList *list);

void ballVoidCollision(Ball *ball, Scene* scene);