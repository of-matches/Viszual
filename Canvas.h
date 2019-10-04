#ifndef Canvas_H
#define Canvas_H

#include <GL/freeglut.h>
#include <windows.h>
#include <gl/GL.h>

using namespace std;

class Canvas{
    public:
        Canvas(int argc, char **argv);

        float platformTranslateX = -3;
    	float platformTranslateZ = -3;
        unsigned short int platformPhase = 0;
        float cubeTranslate = 0.6;
        bool cubeUpMovement = true;
        float cubeRotate;

        void init();
};

#endif