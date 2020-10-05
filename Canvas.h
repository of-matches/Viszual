#ifndef Canvas_H
#define Canvas_H

#include "Scene.h"
#include <thread>

class Canvas{
    public:
        Canvas();
        Canvas(int argc, char **argv);
        
    private:
        unsigned short windowSize;
        
        void init(int argc, char** argv);

};

#endif