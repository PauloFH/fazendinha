#include "Ground.h"
#include "Fazendinha.h"

Ground::Ground(int posX, int posY, bool toPut) {

	normal = new Sprite("Resources/solo1.png");
	molhado = new Sprite("Resources/solo1Molhado.png");

	sprite = normal;

	MoveTo(posX, posY);
	BBox(new Rect(-8, -8, 7, 7));

	if (toPut) {
		type = GRASS;
	}
	else {
		type = GROUND;
	}

	Scale(2.0);

}
Ground::~Ground() {
	// nao deleta o floor
}

void Ground::Update() {

}

void Ground::Draw() {
	
	/*if (type == GRASS) {
		sprite->Draw(x, y, Layer::LOWER);
	}
	if (type == GROUND) {
		sprite->Draw(x, y, Layer::MIDDLE);
	}*/
	sprite->Draw(x, y, Layer::BACK, scale);
}

void Ground::OnCollision(Object* obj) {

	/*if (type == GROUND && obj->Type() == MOUSE) {
		obj->MoveTo(x, y);
	}
	*/
}