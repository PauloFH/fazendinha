#include "Bau.h"
#include "Fazendinha.h"

Bau::Bau() {
	sprite = new Sprite("Resources/bau.png");
	bauOpened = new BauSpaces();
	Fazendinha::scene->Add(bauOpened, STATIC);

	MoveTo(Fazendinha::player->X(), Fazendinha::player->Y() - 100);

	BBox(new Rect(-8, -8, 7, 16));
	type = BAU;

	Scale(2.0);
}

Bau::~Bau() {
	//delete bauOpened;
	delete sprite;
}

void Bau::Update() {
	if (opened) {

		if (window->KeyPress(VK_RBUTTON)|| Fazendinha::gamepad->XboxButton(ButtonB)) {
			opened = false;
			bauOpened->isOpen = false;
			bauOpened->MoveTo(100000, 100000);
		}
	}
}

void Bau::OnCollision(Object* obj) {
	if (obj->Type() == MOUSE) {
		if (!opened && window->KeyPress(VK_LBUTTON) || Fazendinha::gamepad->XboxButton(ButtonB)) {
			opened = true;
			bauOpened->isOpen = true;
			bauOpened->MoveTo(game->viewport.left + window->Width() / 2, game->viewport.top + window->Height() / 2);

		}
	}
}
