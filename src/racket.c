#include "corridor.h"
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <math.h>
#include <3D_tools.h>
#include "racket.h"
#include "obstacle.h"
#include "scene.h"

Racket *createRacket(){
    Racket *racket = (Racket*)malloc(sizeof(Racket));
    racket->racketSize = 1.5;
    racket->x = 0;
    racket->y = 0;
    return racket;
}

void updateRacket(Racket *racket, double x, double y, Scene scene){
    float h = WINDOW_HEIGHT;
    float w = WINDOW_WIDTH;

    float racketSize = racket->racketSize;

    racket->x = fmin(scene.width/2.0 - racketSize/2.0, fmax(-scene.width/2.0 + racketSize/2.0, -(scene.width/w) * (x - (w/2.))));
    racket->y = fmin(scene.height/2.0 - racketSize/2.0, fmax(-scene.height/2.0 + racketSize/2.0, -(scene.height/h) * (y - (h/2.))));

}

void drawRacket(Racket racket){
    float racketSize = racket.racketSize;

    glPushMatrix();
        glTranslatef(racket.x, racket.y, 0);
        glBegin(GL_LINES);
            glColor3f(1, 1, 1);

            glVertex3f(-racketSize/2., -racketSize/2., 0);
            glVertex3f(-racketSize/2., racketSize/2., 0);

            glVertex3f(-racketSize/2., racketSize/2., 0);
            glVertex3f(racketSize/2., racketSize/2., 0);

            glVertex3f(racketSize/2., racketSize/2., 0);
            glVertex3f(racketSize/2., -racketSize/2., 0);

            glVertex3f(racketSize/2., -racketSize/2., 0);
            glVertex3f(-racketSize/2., -racketSize/2., 0);
        glEnd();
    glPopMatrix();
}

void getRacketCoords(GLFWwindow* window, double *x, double *y){
    glfwGetCursorPos(window, &(*x), &(*y));
}
