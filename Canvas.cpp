#include "Canvas.h"

unsigned short timeUntilNextTick;
Scene* scene;

void updateDisplay(){
	glLoadIdentity();  // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

	scene->render();

	glutSwapBuffers();
}

void incrementTick(int value){
	scene->animate();
	updateDisplay();
	glutTimerFunc(timeUntilNextTick, incrementTick, ++value);
}

void reshape(int width, int height){
	glMatrixMode(GL_PROJECTION);// Matrix für Transformation: Frustum->viewport
	glLoadIdentity();// Aktuelle Transformations-Matrix zuruecksetzen
	glViewport(0, 0, width, height);// Viewport definieren
	gluPerspective(90, 1, 0.1, 16);// Frustum definieren
	glMatrixMode(GL_MODELVIEW);// Matrix für Modellierung/Viewing
}

Canvas::Canvas(int argc, char **argv){
	windowSize = 512;
	timeUntilNextTick = 10;	//in ms

    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_ALPHA);
	glutInitWindowSize(windowSize, windowSize);
	glutCreateWindow("Canvas");

	glutReshapeFunc(reshape);
	glutDisplayFunc(updateDisplay);
	glutTimerFunc(timeUntilNextTick, incrementTick, 0);

	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);

	scene = new Scene();
	glutMainLoop();
}