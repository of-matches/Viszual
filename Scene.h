#ifndef Scene_H
#define Scene_H

#include <vector>
#include "Cube.h"

using namespace std;

class Scene{
    public:
        Scene();

        void render();
        void createCubes(const int number);

    private:
        vector<Cube> cubes;
};

#endif