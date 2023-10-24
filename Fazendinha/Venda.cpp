#include "Venda.h"
#include "Fazendinha.h"

Venda::Venda() {

	tileset = new TileSet("Resources/venda.png", 16, 36, 6, 6);
	animation = new Animation(tileset, 0.2f, false);
	
	uint normal[1] = { 0 };
	uint opening[4] = { 2, 3, 4, 5 };
	uint closing[4] = { 5, 4, 3, 2 };

	animation->Add(NORMAL, normal, 1);
	animation->Add(OPENING, opening, 4);
	animation->Add(CLOSING, closing, 4);

	BBox(new Rect(-8, -18, 7, 17));

	Scale(2.0f);

	type = VENDA;
}

Venda::~Venda() {
	delete tileset;
	delete animation;
}

void Venda::Update() {
	animation->Select(state);
	animation->NextFrame();
	
	if (open) {
		state = CLOSING;
		open = false;
	}
	if (!open && animation->Frame() == 2) {
		state = CLOSED;
	}
}

void Venda::OnCollision(Object* obj) {
	if (obj->Type() == MOUSE) {
		if (!open) {
			open = true;
			state = OPENING;
		}
	}

	if (obj->Type() == ITEM) {
		Item* item = dynamic_cast<Item*>(obj);
		if (open) {
			if (!item->pego && window->KeyPress('R')) {
				Fazendinha::player->dinheiro += item->precoItem;
				Fazendinha::scene->Remove(item, MOVING);
				Fazendinha::mouse->carrying = false;
				Fazendinha::mouse->itemHolded = nullptr;
			}
		}
	}
	//if(!open && Fazendinha::mouse)
}
