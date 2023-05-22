#include "scene.h"

Scene *createScene(){
    Scene *scene = (Scene*)malloc(sizeof(Scene));
    scene->width = 10.;
    scene->height = (scene->width / WINDOW_WIDTH) * WINDOW_HEIGHT;
    scene->playerMoving = 0;
    scene->movingSpeed = .2;
    return scene;
}