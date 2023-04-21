#include "corridor.h"
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <math.h>
#include <3D_tools.h>

void drawRacket(double x, double y, int w, int h, float ar){

    double racketSize = 1.5;

    double glWallWidth = 10;
    double glWallHeight = (glWallWidth / w) * h;
    double distance = glWallHeight / (2 * tan(toRad(30.)));

    // double glPosX = -(glWallWidth/w) * (x - (w/2.));
    // double glPosY = -(glWallWidth/w) * (y - (h/2.));

    double glPosX = fmin(glWallWidth/2.0 - racketSize/2.0, fmax(-glWallWidth/2.0 + racketSize/2.0, -(glWallWidth/w) * (x - (w/2.))));
    double glPosY = fmin(glWallHeight/2.0 - racketSize/2.0, fmax(-glWallHeight/2.0 + racketSize/2.0, -(glWallWidth/w) * (y - (h/2.))));


    
    glPushMatrix();
        glTranslatef(glPosX, glPosY, distance);
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