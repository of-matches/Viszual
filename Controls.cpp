#include "Controls.h"

Controls::Controls(){
    auto app = Gtk::Application::create();    
    Gtk::Window window;
    window.set_default_size(400,600);   
    app->run(window);
}