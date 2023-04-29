#include "corridor.h"
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <math.h>
#include <3D_tools.h>
#include "obstacle.h"
#include "racket.h"

Racket *createRacket(){
    Racket *racket = (Racket*)malloc(sizeof(Racket));
    racket->racketSize = 1.5;
    racket->x = 0;
    racket->y = 0;
    return racket;
}

void updateRacket(Racket *racket, double x, double y, int w, int h){
    double glWallWidth = 10;
    double glWallHeight = (glWallWidth / w) * h;
    float racketSize = racket->racketSize;

    racket->x = fmin(glWallWidth/2.0 - racketSize/2.0, fmax(-glWallWidth/2.0 + racketSize/2.0, -(glWallWidth/w) * (x - (w/2.))));
    racket->y = fmin(glWallHeight/2.0 - racketSize/2.0, fmax(-glWallHeight/2.0 + racketSize/2.0, -(glWallWidth/w) * (y - (h/2.))));

}

void drawRacket(Racket racket, int w, int h){

    float racketSize = racket.racketSize;
    double glWallWidth = 10;
    double glWallHeight = (glWallWidth / w) * h;

    double distance = glWallHeight / (2 * tan(toRad(30.)));

    glPushMatrix();
        glTranslatef(racket.x, racket.y, distance);
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

int chocObstacle(ObstList list, Racket racket){
    Obst* obst;
    float size = racket.racketSize/2.;
    
    for (obst = list.first; obst != NULL;obst = obst->next) {
        
		if(obst->z <= 0.5){
            if(racket.x - size < obst->x + obst->width/2. &&
                racket.x + size > obst->x - obst->width/2. &&
                racket.y - size < obst->y + obst->height/2. &&
                racket.y + size > obst->y - obst->height/2.){
                    return 0;
            }
        }
	}
    return 1;
}