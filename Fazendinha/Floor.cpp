#include "Floor.h"

Floor::Floor(int posX, int posY, bool toPut) {

	sprite = new Sprite("Resources/floor.png");

	MoveTo(posX, posY);
	BBox(new Rect(-34, -34, 33, 33));

	if (toPut) {
		type = FLOORSPACE;
	}
	else {
		type = FLOOR;
	}
}

Floor::~Floor() {
	// nao deleta o floor
}

void Floor::Update() {

}

void Floor::Draw() {
	if (type == FLOORSPACE) {
		sprite->Draw(x, y, Layer::LOWER);
	}
	if (type == FLOOR) {
		sprite->Draw(x, y, Layer::MIDDLE);
	}
}

void Floor::OnCollision(Object* obj) {

	if (type == FLOORSPACE && obj->Type() == MOUSE) {
		obj->MoveTo(x, y);
	}

}