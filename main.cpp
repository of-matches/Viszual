#include <thread>
#include <gtk-3.0/gtk/gtk.h>
#include "Canvas.h"

static void on_activate (GtkApplication *app){
  // Create a new window
  GtkWidget *window = gtk_application_window_new (app);
  // Create a new button
  GtkWidget *button = gtk_button_new_with_label ("Hello, World!");
  // When the button is clicked, destroy the window passed as an argument
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
  gtk_container_add (GTK_CONTAINER (window), button);
  gtk_widget_show_all (window);
}

void startCanvasThread(int argc, char **argv){
    Canvas canvas(argc, argv);
}

int main(int argc, char **argv){
    std::thread canvasThread (startCanvasThread, argc, argv);
    canvasThread.detach();

    GtkApplication *app = gtk_application_new ("com.example.GtkApplication", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (on_activate), NULL);
    return g_application_run (G_APPLICATION (app), argc, argv);
}