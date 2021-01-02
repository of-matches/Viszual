#ifndef Controls_H
#define Controls_H

#include "Canvas.h"
#include <gtkmm/window.h>
#include <gtkmm/button.h>

class Controls : public Gtk::Window {
    public:
        Controls(Canvas* canvas);

    private:
        Canvas* canvas;
        Gtk::Button buttonAddScene;

        void buttonAddSceneClicked();

};

#endif