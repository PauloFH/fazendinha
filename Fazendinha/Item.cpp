#include "Item.h"
#include "Fazendinha.h"

Item::Item(uint itType = 0, InventorySpace* spc = nullptr) {
	
	itemType = itType;
	space = spc;

	if (itemType == ITEMCHIRIVIA) {
		sprite = new Sprite("Resources/Items/chirivia.png");
	}
	else if (itemType == SEEDCHIRIVIA) {
		sprite = new Sprite("Resources/Items/seedChirivia.png");
	}

	BBox(new Rect(-24, -24, 23, 23));

	type = ITEM;
}

Item::~Item() {
	delete sprite;
}

void Item::Update() {
	if (!moving) {
		MoveTo(space->X(), space->Y());
		space->ocupado = true;
	}
}

void Item::Draw() {
	sprite->Draw(x, y, Layer::FRONT, scale);
}

void Item::OnCollision(Object* obj) {
	if (obj->Type() == MOUSE) {
		if (!Fazendinha::mouse->carrying && window->KeyPress(VK_LBUTTON)) {
			Fazendinha::mouse->carrying = true;
			Fazendinha::mouse->itemHolded = this;
			moving = true;
		}

		if (Fazendinha::mouse->carrying && Fazendinha::mouse->itemHolded == this && window->KeyPress(VK_LBUTTON)) {

			Fazendinha::mouse->carrying = false;
			Fazendinha::mouse->itemHolded = nullptr;
			moving = false;

		}
	}

}