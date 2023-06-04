#include "scene.h"

Scene *createScene(){
    Scene *scene = (Scene*)malloc(sizeof(Scene));
    scene->width = 10.;
    scene->height = (scene->width / WINDOW_WIDTH) * WINDOW_HEIGHT;
    scene->playerMoving = 0;
    scene->movingSpeed = .15;
    scene->gameState = MENU;
    scene->lives = 3;
    return scene;
}

void drawLives(Scene *scene) {
    if(scene->lives > 1){
        glColor3f(0.3,0.6,0.6);
    }
    else{
        glColor3f(0.6,0.3,0.3);
    }
	glPushMatrix();
        for(int i = 0; i < scene->lives; i++){
            glPushMatrix();
                glTranslatef(scene->width/2. - i*scene->width/12. - 1, -scene->height/2. + .8, -.3);
                glScalef(.3, .3, .3);
                drawCircle();
            glPopMatrix();
        }
	glPopMatrix();
}

void startGame(Scene scene){
    glPushMatrix();
        glColor3f(0,0,1);
		glScalef(scene.width, scene.height, 0);
		drawSquare();
	glPopMatrix();
}

void gameOver(Scene scene){
    glPushMatrix();
        glColor3f(1,0,0);
		glScalef(scene.width, scene.height, 0);
		drawSquare();
	glPopMatrix();
}