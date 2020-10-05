#include "Controls.h"

Controls::Controls(Canvas* canvas) : buttonHide("Hide") {
    Gtk::Window window;
    buttonHide.signal_clicked().connect(sigc::mem_fun(*this, &Controls::buttonHideClicked));
    add(buttonHide);
    buttonHide.show();
}

void Controls::buttonHideClicked()
{
  //std::cout << "Hello World" << std::endl;
}