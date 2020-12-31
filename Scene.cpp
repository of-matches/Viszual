#include "Scene.h"

Scene::Scene() {
    createCubes(2);
}

void Scene::render() const{
    Cube cube;
    Axis rotationAxis;

    for(unsigned int i = 0; i < cubes.size(); i++) {
        cube = cubes.at(i);
        rotationAxis = cube.getRotationAxis();

        glPushMatrix();
        glRotatef(cube.getRotation(), rotationAxis.x, rotationAxis.y, rotationAxis.z);
        cubes.at(i).draw();
        glPopMatrix();
    }
}

void Scene::animate() {
    for(unsigned int i = 0; i < cubes.size(); i++) {
        cubes.at(i).incrementRotation(1);
    }
}

void Scene::createCubes(const int number) {
    for (unsigned short i = 0; i < number; i++){
        cubes.emplace_back(i +1, Axis(1, 0.5, (i +1)), Color(1, 1, 1, 0));
    }
}