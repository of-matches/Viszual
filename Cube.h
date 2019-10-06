#ifndef Cube_H
#define Cube_H

#include "Position.h"
#include "Color.h"

class Cube{
    public:  
        Cube(const float diameter, const Color color);
        void draw();

    private:
        float diameter;
        Color color;
        Position position;
};

#endif