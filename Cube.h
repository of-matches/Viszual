#ifndef Cube_H
#define Cube_H

#include "Position.h"
#include "Color.h"
#include "Axis.h"

class Cube{
    public:
        Cube();
        Cube(const GLfloat size, const Axis rotationAxis, const Color color);

        void draw() const;
        void incrementRotation(const unsigned short angle);
        GLfloat getRotation();
        Axis getRotationAxis();

    private:
        GLfloat size;
        Axis rotationAxis;
        Color color;
        GLfloat rotation;
        Position position;

};

#endif