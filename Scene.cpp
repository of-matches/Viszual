#include "Scene.h"

Scene::Scene(){
    createCubes(1);
}

void Scene::render(){
    glLoadIdentity ();  // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

    for(int i = 0; i < cubes.size(); i++){
        cubes.at(i).draw();
    }

	glutSwapBuffers();
}

void Scene::createCubes(const int number){
    for (short i = 0; i < number; i++){
        cubes.emplace_back(1, Color(0, 0, 0, 1));
    }
}