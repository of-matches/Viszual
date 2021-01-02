#ifndef Canvas_H
#define Canvas_H

#include "Scene.h"
#include <thread>
#include <forward_list>

extern unsigned short minMillisecondsBetweenRenders;

class Canvas{
    public:
        Canvas();
        Canvas(int argc, char **argv);

        void render();
        void animate();
        void addScene();
        
    private:
        unsigned short windowSize;
        std::forward_list<Scene> sceneList;
        
        void init(int argc, char** argv);

};

extern Canvas* mainCanvas;

#endif