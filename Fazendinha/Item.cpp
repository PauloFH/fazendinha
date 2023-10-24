#include "Item.h"
#include "Fazendinha.h"

Item::Item(uint itType, InventorySpace* spc) {
	
	itemType = itType;
	space = spc;

	if (itemType == ITEMCHIRIVIA) {
		sprite = new Sprite("Resources/Items/chirivia.png");
	}
	else if (itemType == SEEDCHIRIVIA) {
		sprite = new Sprite("Resources/Items/seedChirivia.png");
	}

	if (itemType == ITEMREGADOR) {
		sprite = new Sprite("Resources/Items/regador.png");
	}

	if (itemType == ITEMARADOR) {
		sprite = new Sprite("Resources/Items/arador.png");
	}

	BBox(new Rect(-24, -24, 23, 23));

	type = ITEM;
}

Item::~Item() {
	delete sprite;
}

void Item::Update() {

	if (pego) {
		//MoveTo(Fazendinha::player->X(), Fazendinha::player->Y() + 100);
		if (!moving && space != nullptr && space->X() != -10000) {
			MoveTo(space->X(), space->Y());
			space->ocupado = true;
		}
		if (space->X() == -10000) {
			space->ocupado = true;
		}
	}
	else {
		if (!moving && space != nullptr && space->X() != -10000) {
			MoveTo(space->X(), space->Y());
			space->ocupado = true;
		}
		if (space->X() == -10000) {
			space->ocupado = true;
		}
	}

}

void Item::Draw() {
	sprite->Draw(x, y, Layer::FRONT, scale);
}

void Item::OnCollision(Object* obj) {
	if (obj->Type() == MOUSE) {
		if (!pego && !Fazendinha::mouse->carrying && window->KeyPress(VK_LBUTTON)) {
			Fazendinha::mouse->carrying = true;
			Fazendinha::mouse->itemHolded = this;
			if (Fazendinha::mouse->itemHolded->space != nullptr) {
				Fazendinha::mouse->itemHolded->space->cont--;
			}
			moving = true;
		}

		if (!pego && Fazendinha::mouse->carrying && Fazendinha::mouse->itemHolded == this && window->KeyPress(VK_LBUTTON)) {
			Fazendinha::mouse->carrying = false;
			Fazendinha::mouse->itemHolded->considerado = false;
			Fazendinha::mouse->itemHolded = nullptr;
			moving = false;
		}
	}

}