#ifndef Color_H
#define Color_H

#include <GL/freeglut.h>

struct Color{
    Color();
    Color(const GLfloat r, const GLfloat g, const GLfloat b, const GLfloat a);

    GLfloat r;
    GLfloat g;
    GLfloat b;
    GLfloat a;
};

#endif