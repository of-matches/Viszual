#include "Cube.h"

Cube::Cube(GLfloat size, Color color, Axis rotationAxis): size(size), color(color), rotationAxis(rotationAxis), position(Position(0, 0, 0)), rotation(0){}

void Cube::draw(){
	glColor4f(color.r, color.g, color.b, color.a);
	glutSolidCube(size);
}

Axis Cube::getRotationAxis(){
	return rotationAxis;
}