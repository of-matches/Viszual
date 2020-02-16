#ifndef Cube_H
#define Cube_H

#include "Position.h"
#include "Color.h"
#include "Axis.h"

class Cube{
    public:
        GLfloat rotation;

        Cube();
        Cube(const GLfloat size, const Color color, const Axis rotationAxis);

        void draw();
        Axis getRotationAxis();

    private:
        GLfloat size;
        Axis rotationAxis;
        Color color;
        Position position;
};

#endif