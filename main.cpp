#include <thread>
#include <gtkmm-3.0/gtkmm.h>
#include "Canvas.h"

void startCanvasThread(int argc, char** argv){
    Canvas canvas(argc, argv);
}

int main(int argc, char** argv){
    std::thread canvasThread(startCanvasThread, argc, argv);
    canvasThread.detach();

    auto app = Gtk::Application::create(argc, argv);
        
    Gtk::Window window;
    window.set_default_size(600,400);
        
    return app->run(window);
}