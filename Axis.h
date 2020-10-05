#ifndef Axis_H
#define Axis_H

#include <GL/freeglut.h>

struct Axis{
    Axis();
    Axis(const GLfloat x, const GLfloat y, const GLfloat z);

    GLfloat x;
    GLfloat y;
    GLfloat z;
};

#endif