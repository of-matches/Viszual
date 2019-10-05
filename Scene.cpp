#include "Scene.h"

Scene::Scene(){
    render();
}

void Scene::render(){
    glLoadIdentity ();  // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

	cube(1, 1, 1, 1);

	glutSwapBuffers();
}