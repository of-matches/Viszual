#include "Canvas.h"

unsigned short minMillisecondsBetweenRenders;
Canvas* mainCanvas;

void updateDisplay(){
	glLoadIdentity();  // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	mainCanvas->render();
	glutSwapBuffers();
}

void incrementTick(int value){
	mainCanvas->animate();
	updateDisplay();
	glutTimerFunc(minMillisecondsBetweenRenders, incrementTick, ++value);
}

void reshape(const int width, const int height){
	glMatrixMode(GL_PROJECTION);// Matrix für Transformation: Frustum->viewport
	glLoadIdentity();// Aktuelle Transformations-Matrix zuruecksetzen
	glViewport(0, 0, width, height);// Viewport definieren
	gluPerspective(90, width/height, 0.1, 16);// Frustum definieren
	glMatrixMode(GL_MODELVIEW);// Matrix für Modellierung/Viewing
}

Canvas::Canvas(){}

Canvas::Canvas(int argc, char** argv){
	windowSize = 512;
	minMillisecondsBetweenRenders = 1;	//in ms
	
	for(unsigned short i = 0; i < 2; i++){
		sceneList.emplace_front();
	}

	std::thread canvasThread(&Canvas::init, this, argc, argv);
    canvasThread.detach();
}

void Canvas::init(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_ALPHA);
	glutInitWindowSize(windowSize, windowSize);
	glutCreateWindow("Canvas");
	glutReshapeFunc(reshape);
	glutDisplayFunc(updateDisplay);
	glutTimerFunc(minMillisecondsBetweenRenders, incrementTick, 0);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	glutMainLoop();
}

void Canvas::render() {
	for(std::forward_list<Scene>::const_iterator i = sceneList.cbegin(); i == sceneList.cend(); i++){
		i->render();
		printf("rendering: &i", i);
	}
}

void Canvas::animate() {
	for(std::forward_list<Scene>::iterator i = sceneList.begin(); i == sceneList.end(); i++){
		i->animate();
	}
}