#include "scene.h"
#include "3D_tools.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Scene *createScene(){
    Scene *scene = (Scene*)malloc(sizeof(Scene));
    scene->width = 10.;
    scene->height = (scene->width / WINDOW_WIDTH) * WINDOW_HEIGHT;
    scene->playerMoving = 0;
    scene->movingSpeed = .15;
    scene->gameState = MENU;
    scene->lives = 3;
    scene->advancement = 0;
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

void addTexture(Scene scene, char adresse[]){
    int x, y, n;
    unsigned char* image;
    GLuint texture;

    glColor3f(1,1,1);

	glEnable(GL_TEXTURE_2D);

    image = stbi_load(adresse, &x, &y, &n, 0);

    glGenTextures(1, &texture);

    glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, x, y, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    glPushMatrix();
		glScalef(scene.width, scene.height, 0);
        
		glBegin(GL_TRIANGLE_FAN);

            glTexCoord2f(1, 1);
            glVertex3f(-0.5,-0.5,0.0);

            glTexCoord2f(0, 1);
            glVertex3f(0.5,-0.5,0.0);

            glTexCoord2f(0, 0);
            glVertex3f(0.5,0.5,0.0);

            glTexCoord2f(1, 0);
            glVertex3f(-0.5,0.5,0.0);

	    glEnd();

	glPopMatrix();

    stbi_image_free(image);
    glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glDeleteTextures(1, &texture);
}

EndWall *createEndWall(float z){
    EndWall *endWall = (EndWall*)malloc(sizeof(EndWall));

    endWall->z = z;

    endWall->R = 0;
    endWall->G = 0;
    endWall->B = 0;

    endWall->winScreen = 0;

    return endWall;
}

void drawEndWall(Scene scene, EndWall *endWall){
    glPushMatrix();
		glColor3f(endWall->R, endWall->G, endWall->B);
		glTranslatef(0, 0, endWall->z);
		glScalef(scene.width, scene.height, 0);
		drawSquare();
	glPopMatrix();
}

void updateEndWall(Scene scene, EndWall *endWall){

    if(scene.advancement >= 400 && scene.playerMoving){
        endWall->winScreen = 1;
        endWall->z -= scene.movingSpeed;
        endWall->R = -endWall->z/100+0.3;
        endWall->G = -endWall->z/100+0.6;
        endWall->B = -endWall->z/100+0.6;
    }
}