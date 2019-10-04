#include "Cube.h"

void cube(float diameter, float red, float green, float blue){
	glBegin(GL_POLYGON);   //Vorderseite
	glColor3f(red, green, blue);
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

	glColor3f(red, green, blue);
}