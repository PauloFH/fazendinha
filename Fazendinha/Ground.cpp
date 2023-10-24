#include "Ground.h"
#include "Fazendinha.h"

Ground::Ground(int posX, int posY) {

	normal = new Sprite("Resources/solo1.png");
	arado = new Sprite("Resources/solo1Arado.png");
	molhado = new Sprite("Resources/solo1Molhado.png");

	sprite = normal;

	MoveTo(posX, posY);
	BBox(new Rect(-8, -8, 7, 7));

	type = GROUND;

	Scale(2.0);

}
Ground::~Ground() {
	// nao deleta o floor
}

void Ground::Update() {
	if (isMolhado) {
		sprite = molhado;
		if (planted != nullptr) {
			planted->regada = true;
		}
	}
	else {
		if (isArado) {
			sprite = arado;
		}
		else {
			sprite = normal;
		}
	}

	ocupado = false;
}

void Ground::Draw() {
	
	/*if (type == GRASS) {
		sprite->Draw(x, y, Layer::LOWER);
	}
	if (type == GROUND) {
		sprite->Draw(x, y, Layer::MIDDLE);
	}*/

	sprite->Draw(x, y, Layer::LOWER, scale);
}

void Ground::OnCollision(Object* obj) {

	/*if (type == GROUND && obj->Type() == MOUSE) {
		obj->MoveTo(x, y);
	}
	*/

	/*if (obj->Type() == GROUND) {
		MoveTo(obj->X() + 16, obj->Y());
	}*/

	if (obj->Type() == PLANTATION) {
		Plantation* plt = dynamic_cast<Plantation*>(obj);
		if (isArado) {
			if (!ocupado) {
				ocupado = true;
				obj->MoveTo(x - 1, y - 15, Layer::LOWER - 0.01f);
				plt->objGround = this;
				planted = plt;
			}
		}

		if (!isArado || (ocupado && planted != plt)) {
			Fazendinha::scene->Delete(plt, MOVING);
		}
	}

	/* if (!ocupado && it->itemType == SEEDCHIRIVIA && it->moving && it->pego) {
                    it->space->cont--;
                    planted = new Plantation(CHIRIVIA);
                    Fazendinha::scene->Add(planted, MOVING);
                }
				*/

}