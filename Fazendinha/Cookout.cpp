#include "Fazendinha.h"
#include "Cookout.h"

Cookout::Cookout() {
	sprite = new Sprite("Resources/cookout_kit.png");
	craftMenu = new CraftMenu();
	BBox(new Rect(-10,-10,10,10) );
	Scale(2.0);

	type = COOKOUT;
	MoveTo(Fazendinha::player->X()+50, Fazendinha::player->Y() - 80);
}

void Cookout::Update() {
	if (hit) {
		if (window->KeyPress(VK_RBUTTON)) {
			hit = false;
			//craftMenu->~CraftMenu();
		}
	}
}

void Cookout::OnCollision(Object* obj) {
	if (obj->Type() == MOUSE) {
		if (!hit && window->KeyPress(VK_LBUTTON)) {
			hit = true;

			OutputDebugString("\nPressionou LBUTTON\n");

			Fazendinha::scene->Add(craftMenu, STATIC);
		}
	}
}

Cookout::~Cookout() {
	delete sprite;
	delete craftMenu;
}
