#ifndef Cube_H
#define Cube_H

#include "Position.h"
#include "Color.h"
#include "Axis.h"

class Cube{
    public:
        Cube();
        Cube(const GLfloat size, const Color color, const Axis rotationAxis);

        void draw();
        void incrementRotation(const unsigned short angle);
        GLfloat getRotation();
        Axis getRotationAxis();

    private:
        GLfloat size;
        GLfloat rotation;
        Axis rotationAxis;
        Color color;
        Position position;
};

#endif