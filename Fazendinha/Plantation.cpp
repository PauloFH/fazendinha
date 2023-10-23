#include "Plantation.h"
#include "Fazendinha.h"

Plantation::Plantation(uint plant = CHIRIVIA) {

	initialDay = Fazendinha::dayCount;

	plantationType = plant;
	plantationState = GROWING;

	if (plantationType == CHIRIVIA) {
		numStages = 6;
		tileset = new TileSet("Resources/chirivia.png", 16, 32, numStages, numStages);
	}
	else if (plantationType == COUVEFLOR) {
		numStages = 7;
		tileset = new TileSet("Resources/couve-flor.png", 16, 32, numStages, numStages);
	}

	animation = new Animation(tileset, 0.5f, true);

	BBox(new Rect(-8, -1, 7, 15));
	Scale(2.0);
	MoveTo(Fazendinha::player->X(), Fazendinha::player->Y() + 100);

	type = PLANTATION;

}

Plantation::~Plantation() {
	delete tileset;
	delete animation;
}

void Plantation::Update() {

	if (animation->Frame() == numStages - 1) {
		plantationState = MATURE;
	}
	else if(Fazendinha::timer.Elapsed(600.0f)){
		animation->NextFrame();
	}
	
}

void Plantation::OnCollision(Object* obj) {
	if (obj->Type() == MOUSE) {
		if (plantationState == MATURE && window->KeyPress(VK_LBUTTON)) {
			InventorySpace* tst = new InventorySpace();
			tst->MoveTo(-10000, -10000);
			Item* fruto = new Item(0, tst);
			Fazendinha::scene->Add(fruto, MOVING);
			fruto->MoveTo(x, y);

			Fazendinha::scene->Delete(this, STATIC);
		}
	}
}