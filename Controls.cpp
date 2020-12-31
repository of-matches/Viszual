#include "Controls.h"

Controls::Controls(Canvas* canvas) : togglebuttonHide("Hide") {
    set_border_width(8);

    togglebuttonHide.signal_clicked().connect(sigc::mem_fun(*this, &Controls::togglebuttonHideClicked));
    add(togglebuttonHide);
    togglebuttonHide.show();
}

void Controls::togglebuttonHideClicked() {
  	if(togglebuttonHide.get_active() == true) {
  	} else {

  	}
}