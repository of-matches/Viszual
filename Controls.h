#ifndef Controls_H
#define Controls_H

#include "Canvas.h"
#include <gtkmm/window.h>
#include <gtkmm/togglebutton.h>

class Controls : public Gtk::Window {
    public:
        Controls(Canvas* canvas);

    private:
        Canvas canvas;
        Gtk::ToggleButton togglebuttonHide;

        void togglebuttonHideClicked();

};

#endif