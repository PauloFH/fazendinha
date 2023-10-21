#include "Ground.h"
#include "Fazendinha.h"
Ground::Ground(int posX, int posY, bool toPut) {

	sprite = new Sprite("Resources/Ground.png");

	MoveTo(posX, posY);
	BBox(new Rect(-34, -34, 33, 33));

	if (toPut) {
		type = GRASS;
	}
	else {
		type = GROUND;
	}
}
Ground::~Ground() {
	// nao deleta o floor
}

void Ground::Update() {

}

void Ground::Draw() {
	if (type == GRASS) {
		sprite->Draw(x, y, Layer::LOWER);
	}
	if (type == GROUND) {
		sprite->Draw(x, y, Layer::MIDDLE);
	}
}

void Ground::OnCollision(Object* obj) {

	/*if (type == GROUND && obj->Type() == MOUSE) {
		obj->MoveTo(x, y);
	}
	*/
}