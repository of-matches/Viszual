#include "Canvas.h"

short timeUntilNextTick;
Scene* scene;

void incrementTick(int value){
	scene->render();
}

void updateDisplay(){
	scene->render();
}

void reshape(int width, int height){
	glMatrixMode(GL_PROJECTION);// Matrix f�r Transformation: Frustum->viewport
	glLoadIdentity();// Aktuelle Transformations-Matrix zuruecksetzen
	glViewport(0, 0, width, height);// Viewport definieren
	gluPerspective(90, 1, 0.1, 16);// Frustum definieren
	glMatrixMode(GL_MODELVIEW);// Matrix f�r Modellierung/Viewing
}

Canvas::Canvas(int argc, char **argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(400, 400);
	glutCreateWindow("Canvas");
	glutReshapeFunc(reshape);
	glutDisplayFunc(updateDisplay);

	glutTimerFunc(timeUntilNextTick, incrementTick, 0);

	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);

	glutMainLoop();
	Scene();
}