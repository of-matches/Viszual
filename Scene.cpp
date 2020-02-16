#include "Scene.h"

Scene::Scene(){
    createCubes(1);
}

void Scene::render(){
    glLoadIdentity ();  // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

    for(int i = 0; i < cubes.size(); i++){
        Axis rotationAxis = cubes.at(i).getRotationAxis();
        glRotatef(cubes.at(i).rotation, rotationAxis.x, rotationAxis.y, rotationAxis.z);

        cubes.at(i).draw();
    }

	glutSwapBuffers();
}

void Scene::animate(){
    for(int i = 0; i < cubes.size(); i++){
        cubes.at(i).rotation += 2;
    }
}

void Scene::createCubes(const int number){
    for (short i = 0; i < number; i++){
        cubes.emplace_back(1, Color(1, 1, 1, 0), Axis(1, 1, 1));
    }
}