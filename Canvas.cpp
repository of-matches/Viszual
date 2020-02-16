#include "Canvas.h"

unsigned short timeUntilNextTick;
Scene* scene;

void incrementTick(int value){
	scene->animate();
	scene->render();
	glutTimerFunc(timeUntilNextTick, incrementTick, ++value);
}

void updateDisplay(){
	scene->render();
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