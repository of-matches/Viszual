#ifndef Canvas_H
#define Canvas_H

#include "Scene.h"

class Canvas{
    public:
        Canvas(int argc, char **argv);
    
    private:
        unsigned short windowSize;
        void init();
};

#endif