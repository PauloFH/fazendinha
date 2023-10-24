#include "Fazendinha.h"
#include "Cookout.h"

Cookout::Cookout() {
	sprite = new Sprite("Resources/cookout_kit.png");
	type = COOKOUT;
	MoveTo(Fazendinha::player->X()+50, Fazendinha::player->Y() - 80, Layer::MOSTBACK);
	BBox(new Rect(-10,-15,10,5) );
	Scale(2.0);

	cm = new CraftMenu();
	Fazendinha::scene->Add(cm, STATIC);
}

void Cookout::Update() {
	if (opened) {
		if (window->KeyPress(VK_RBUTTON)) {
			opened = false;
			cm->isOpen = false;
			cm->MoveTo(1, 2, 10);
		}
	}
}

void Cookout::OnCollision(Object* obj) {
	
	if (obj->Type() == MOUSE) {
		if (opened == false && window->KeyPress(VK_LBUTTON)) {
			opened = true;
			cm->isOpen = true;
			cm->MoveTo(game->viewport.left+window->Width()/2,game->viewport.top+window->Height()/2);
		}
	}
}

Cookout::~Cookout() {
	delete sprite;
	delete cm;
}
