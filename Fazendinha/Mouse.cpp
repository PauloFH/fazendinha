#include "Mouse.h"
#include "Fazendinha.h"
#include <sstream>

bool Mouse::carrying;
uint Mouse::state = PLENO;
Mouse::Mouse() {

	MoveTo(window->MouseX() + game->viewport.left, window->MouseY() + game->viewport.top);

	state = PLENO;
	carrying = false;
	BBox(new Rect(-8, -8, 7, 7));

	Scale(2.0);

	type = MOUSE;
}

Mouse::~Mouse() {

}

void Mouse::Update() {

	state = PLENO;
	MoveTo(window->MouseX() + game->viewport.left, window->MouseY() + game->viewport.top);

	if (carrying) {
		itemHolded->MoveTo(x, y);
	}
	
}

void Mouse::OnCollision(Object * obj) {
	if (obj->Type() == GROUND) {
		if (x > obj->X() - 16 && x < obj->X() + 15 && y > obj->Y() - 16 && y < obj->Y() + 15) {
			state = COLISAO;
		}
		state = COLISAO;
	}

	if (carrying) {
		if (obj->Type() == SPACE) {
			InventorySpace* spc = dynamic_cast<InventorySpace*>(obj);
			if (!spc->ocupado) {
				itemHolded->space = spc;
			}
		}
	}
}