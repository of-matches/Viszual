#ifndef Controls_H
#define Controls_H

#include "Canvas.h"
#include <gtkmm.h>

class Controls : public Gtk::Window {
    public:
        Controls(Canvas* canvas);

    private:
        Canvas canvas;
        Gtk::Button buttonHide;

        void buttonHideClicked();

};

#endif