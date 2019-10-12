#include "Cube.h"

Cube::Cube(const float diameter, const Color color){
	position = Position(0);
	this->diameter = diameter;
	this->color = color;
}

void Cube::draw(){
	glColor4f(color.r, color.g, color.b, color.a);

	glBegin(GL_POLYGON);   //Vorderseite
	glVertex3f(-diameter / 2.0f, -diameter / 2.0f, +diameter / 2.0f);
	glVertex3f(+diameter / 2.0f, -diameter / 2.0f, +diameter / 2.0f);
	glVertex3f(+diameter / 2.0f, +diameter / 2.0f, +diameter / 2.0f);
	glVertex3f(-diameter / 2.0f, +diameter / 2.0f, +diameter / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Rechte Seite
	glVertex3f(+diameter / 2.0f, -diameter / 2.0f, +diameter / 2.0f);
	glVertex3f(+diameter / 2.0f, -diameter / 2.0f, -diameter / 2.0f);
	glVertex3f(+diameter / 2.0f, +diameter / 2.0f, -diameter / 2.0f);
	glVertex3f(+diameter / 2.0f, +diameter / 2.0f, +diameter / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Rueckseite
	glVertex3f(+diameter / 2.0f, +diameter / 2.0f, -diameter / 2.0f);
	glVertex3f(+diameter / 2.0f, -diameter / 2.0f, -diameter / 2.0f);
	glVertex3f(-diameter / 2.0f, -diameter / 2.0f, -diameter / 2.0f);
	glVertex3f(-diameter / 2.0f, +diameter / 2.0f, -diameter / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Linke Seite
	glVertex3f(-diameter / 2.0f, +diameter / 2.0f, -diameter / 2.0f);
	glVertex3f(-diameter / 2.0f, -diameter / 2.0f, -diameter / 2.0f);
	glVertex3f(-diameter / 2.0f, -diameter / 2.0f, +diameter / 2.0f);
	glVertex3f(-diameter / 2.0f, +diameter / 2.0f, +diameter / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Deckflaeche
	glVertex3f(-diameter / 2.0f, +diameter / 2.0f, +diameter / 2.0f);
	glVertex3f(+diameter / 2.0f, +diameter / 2.0f, +diameter / 2.0f);
	glVertex3f(+diameter / 2.0f, +diameter / 2.0f, -diameter / 2.0f);
	glVertex3f(-diameter / 2.0f, +diameter / 2.0f, -diameter / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Bodenflaeche
	glVertex3f(-diameter / 2.0f, -diameter / 2.0f, -diameter / 2.0f);
	glVertex3f(+diameter / 2.0f, -diameter / 2.0f, -diameter / 2.0f);
	glVertex3f(+diameter / 2.0f, -diameter / 2.0f, +diameter / 2.0f);
	glVertex3f(-diameter / 2.0f, -diameter / 2.0f, +diameter / 2.0f);
	glEnd();
}