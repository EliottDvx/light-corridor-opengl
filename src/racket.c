#include "corridor.h"
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <math.h>

void drawRacket(double x, double y, int w, int h, float ar){

    double distance = -10. / (2. * tan(60./2.));

    double glPosX = -(10./w) * (x - (w/2.));
    double glPosY = -(10./w) * (y - (h/2.));

    
    double racketSize = .1;


    
    glPushMatrix();
        glTranslatef(glPosX, glPosY, distance);
        glBegin(GL_LINES);
            glColor3f(1, 1, 1);
            glVertex3f(-racketSize/2., -racketSize/2., 0);
            glVertex3f(-racketSize/2., racketSize/2., 0);
            glVertex3f(racketSize/2., racketSize/2., 0);
            glVertex3f(racketSize/2., -racketSize/2., 0);
            glVertex3f(-racketSize/2., -racketSize/2., 0);
        glEnd();
    glPopMatrix();
}

void getRacketCoords(GLFWwindow* window, double *x, double *y){
    glfwGetCursorPos(window, &(*x), &(*y));
}