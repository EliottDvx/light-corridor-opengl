#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "3D_tools.h"
#include "corridor.h"
#include "racket.h"
#include "ball.h"
#include "obstacle.h"
#include "scene.h"

/* Window properties */
static const char WINDOW_TITLE[] = "TD04 Ex01";
static float aspectRatio = 1.0;

/* Minimal time wanted between two images */
static const double FRAMERATE_IN_SECONDS = 1. / 60.;

/* Racket Coordinates */
double racketX, racketY;

unsigned int WINDOW_WIDTH = 1280;
unsigned int WINDOW_HEIGHT = 720;

/*Gestion des touches*/
int leftClic = 0;

/* Error handling function */
void onError(int error, const char* description)
{
	fprintf(stderr, "GLFW Error: %s\n", description);
}

void onWindowResized(GLFWwindow* window, int width, int height)
{
	aspectRatio = width / (float) height;
	WINDOW_HEIGHT = height;
	WINDOW_WIDTH = width;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0,aspectRatio,Z_NEAR,Z_FAR);
	glMatrixMode(GL_MODELVIEW);
}

void onKey(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) {
		switch(key) {
			case GLFW_KEY_A :
			case GLFW_KEY_ESCAPE :
				glfwSetWindowShouldClose(window, GLFW_TRUE);
				break;
			case GLFW_KEY_L :
				glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
				break;
			case GLFW_KEY_P :
				glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
				break;
			case GLFW_KEY_KP_9 :
				if(dist_zoom<100.0f) dist_zoom*=1.1;
				printf("Zoom is %f\n",dist_zoom);
				break;
			case GLFW_KEY_KP_3 :
				if(dist_zoom>1.0f) dist_zoom*=0.9;
				printf("Zoom is %f\n",dist_zoom);
				break;
			case GLFW_KEY_UP :
				break;
			case GLFW_KEY_DOWN :
				break;
			case GLFW_KEY_LEFT :
				break;
			case GLFW_KEY_RIGHT :
				break;
			case GLFW_KEY_F11 :
				if (glfwGetWindowMonitor(window) == NULL) {
                    // Activer le mode plein écran
                    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
                    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
                    glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
                } else {
                    // Désactiver le mode plein écran
                    glfwSetWindowMonitor(window, NULL, 100, 100, 1280, 720, GLFW_DONT_CARE);
                }
				break;
			default: fprintf(stdout,"Touche non gérée (%d)\n",key);
		}
	}
}

void onClic(GLFWwindow* window, int button, int action, int mods){
	if(action == GLFW_PRESS){
		switch(button){
			case GLFW_MOUSE_BUTTON_LEFT :
				leftClic = 1;
				break;
			default: fprintf(stdout,"Touche non gérée (%d)\n",button);
		}
	}
	if(action == GLFW_RELEASE){
		switch(button){
			case GLFW_MOUSE_BUTTON_LEFT :
				leftClic = 0;
				break;
			default: fprintf(stdout,"Touche non gérée (%d)\n",button);
		}
	}
}

int main(int argc, char** argv)
{
	Scene *scene = createScene();
	Racket *racket = createRacket();

    double distance = scene->height / (2 * tan(toRad(30.)));

	LineList lineList;
    initListLine(&lineList);
	for(int i = 0; i<20; i++){
		addLine(&lineList, i*5);
	}

	ObstList obstList;
    initListObst(&obstList);
	for(int i = 1; i<=5; i++){
		addObst(&obstList, i*20, *scene, racket);
	}
	
	Ball *ball = createBall();

	/* GLFW initialisation */
	GLFWwindow* window;
	if (!glfwInit()) return -1;

	/* Callback to a function if an error is rised by GLFW */
	glfwSetErrorCallback(onError);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
	if (!window)
	{
		// If no context created : exit !
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glfwSetWindowAspectRatio(window, 16, 9);
	glfwSetWindowSizeLimits(window, 640, 360, GLFW_DONT_CARE, GLFW_DONT_CARE);


	glfwSetWindowSizeCallback(window,onWindowResized);
	glfwSetKeyCallback(window, onKey);
	glfwSetMouseButtonCallback(window, onClic);

	onWindowResized(window,WINDOW_WIDTH,WINDOW_HEIGHT);

	glPointSize(5.0);
	glEnable(GL_DEPTH_TEST);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{

		/* Get time (in second) at loop beginning */
		double startTime = glfwGetTime();

		/* Cleaning buffers and setting Matrix Mode */
		glClearColor(0,0,0,0.0);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		setCamera();

		/* Initial scenery setup */
		glTranslatef(0.,0., distance);

		glPushMatrix();
			glTranslatef(0.,0.,10.);
			drawFrame();
		glPopMatrix();

		drawWall(*scene);
		drawLinesWall(scene, &lineList);

		drawObstacle(scene, &obstList, racket);

		drawBall(*ball);
		updateBall(scene, ball);
		
		getRacketCoords(window, &racketX, &racketY);
		updateRacket(racket, racketX, racketY, *scene);
		drawRacket(*racket);

		scene->playerMoving = racketObstacleCollision(&obstList, *racket) && leftClic;

		/* Scene rendering */

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		/* Elapsed time computation from loop begining */
		double elapsedTime = glfwGetTime() - startTime;
		/* If to few time is spend vs our wanted FPS, we wait */
		if(elapsedTime < FRAMERATE_IN_SECONDS)
		{
			glfwWaitEventsTimeout(FRAMERATE_IN_SECONDS-elapsedTime);
		}

		/* Animate scenery */
	}

	glfwTerminate();
	return 0;
}