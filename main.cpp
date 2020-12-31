#include "Canvas.h"
#include "Controls.h"

int main(int argc, char** argv){
    mainCanvas = new Canvas(argc, argv);
    auto app = Gtk::Application::create(argc, argv);
    Controls controls(mainCanvas);
    app->run(controls);
}