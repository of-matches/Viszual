#ifndef Position_H
#define Position_H

#include <GL/freeglut.h>

struct Position{
    Position();
    Position(const GLfloat x, const GLfloat y, const GLfloat z);

    GLfloat x;
    GLfloat y;
    GLfloat z;
};

#endif