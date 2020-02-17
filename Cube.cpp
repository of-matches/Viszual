#include "Cube.h"
Cube::Cube() {}
Cube::Cube(GLfloat size, Color color, Axis rotationAxis): size(size), color(color), rotationAxis(rotationAxis), position(Position(0, 0, 0)), rotation(0) {}

void Cube::draw(){
	glColor4f(color.r, color.g, color.b, color.a);
	glutWireCube(size);
}

Axis Cube::getRotationAxis(){
	return rotationAxis;
}

GLfloat Cube::getRotation(){
	return rotation;
}

void Cube::incrementRotation(unsigned short angle){
	rotation += angle;
	//if(rotation > 720) {rotation -= 720;}
	//if(rotation < 0) {rotation += 360;}
}