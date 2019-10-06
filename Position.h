#ifndef Position_H
#define Position_H

#include <GL/freeglut.h>

struct Position{
    Position();
    Position(const float value);
    Position(const float x, const float y, const float z);

    float x;
    float y;
    float z;
};

#endif