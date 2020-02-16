#include "Scene.h"

Scene::Scene() {
    createCubes(4);
}

void Scene::render() {
    Cube cube;
    Axis rotationAxis;
    for(int i = 0; i < cubes.size(); i++) {
        cube = cubes.at(i);
        rotationAxis = cube.getRotationAxis();

        glRotatef(cube.getRotation(), rotationAxis.x, rotationAxis.y, rotationAxis.z);

        cubes.at(i).draw();
    }
}

void Scene::animate() {
    for(int i = 0; i < cubes.size(); i++) {
        cubes.at(i).incrementRotation(1);
    }
}

void Scene::createCubes(const int number) {
    for (short i = 0; i < number; i++){
        cubes.emplace_back(4, Color(1, 1, 1, 0), Axis(1, 1, (i/2)));
    }
}