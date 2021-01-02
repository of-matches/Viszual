#include "Controls.h"

Controls::Controls(Canvas* canvas) : canvas(canvas), buttonAddScene("Add Scene"){
    set_border_width(8);

    buttonAddScene.signal_clicked().connect(sigc::mem_fun(*this, &Controls::buttonAddSceneClicked));
    add(buttonAddScene);
    buttonAddScene.show();
}

void Controls::buttonAddSceneClicked() {
    canvas->addScene();
}