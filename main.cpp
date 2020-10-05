#include "Canvas.h"
#include "Controls.h"

int main(int argc, char** argv){
    Canvas* canvas = new Canvas(argc, argv);
    auto app = Gtk::Application::create(argc, argv);
    Controls controls(canvas);
    app->run(controls);
}