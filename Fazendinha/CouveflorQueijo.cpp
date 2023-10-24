#include "CouveflorQueijo.h"
#include "Fazendinha.h"
#include "CraftMenu.h"

CouveflorQueijo::CouveflorQueijo() {
	MoveTo(Fazendinha::player->X() + 95, Fazendinha::player->Y() - 90);
	BBox(new Rect(-10,-15,10,5) );
	Scale(2.0);


}

void CouveflorQueijo::OnCollision(Object* obj) {
	if (obj->Type() == MOUSE){
		if (CraftMenu::isOpen == true && window->KeyPress(VK_LBUTTON)) {
			window->Close();
		}
	}
	
}

void CouveflorQueijo::Update() {
	
}

CouveflorQueijo::~CouveflorQueijo(){ }

