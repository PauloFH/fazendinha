#include "Tool.h"
#include "Fazendinha.h"
#include "Ground.h"

Tool::Tool() {
	tileset = new TileSet("Resources/regador.png", 16, 32, 5, 5);
	animation = new Animation(tileset, 0.2, true);


	uint front[2] = { 0, 1 };
	uint side[2] = { 2, 3 };

	animation->Add(TOOLFRONT, front, 2);
	animation->Add(TOOLSIDE, side, 2);

	BBox(new Rect(-4, 8, 4, 15));

	Scale(2.0);

	type = REGADOR;

}

Tool::~Tool() {
	delete tileset;
	delete animation;
}

void Tool::Update() {

	if (animation->Frame() == 1 || animation->Frame() == 3) {
		if (timer.Elapsed(2.0f)) {
			animation->NextFrame();
			Fazendinha::scene->Delete();
		}
	}
	else {
		animation->NextFrame();
		timer.Start();
	}

	animation->Select(state);

}

void Tool::OnCollision(Object* obj) {
	if (obj->Type() == GROUND) {
		Ground* ground = dynamic_cast<Ground*>(obj);
		if (!ground->isMolhado) {
			ground->isMolhado = true;
		}
	}
}
