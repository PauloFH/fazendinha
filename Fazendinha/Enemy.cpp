#include "Enemy.h"
#include "Fazendinha.h"

Enemy::Enemy() {
	tileset = new TileSet("Resources/bug1.png", 16, 16, 4, 17);
	animation = new Animation(tileset, 0.2f, true);

	BBox(new Rect(-8, -8, 7, 7));

	Scale(2.0);

	MoveTo(Fazendinha::player->X(), Fazendinha::player->Y() - 200);

	type = ENEMY;

}

Enemy::~Enemy() {
	delete animation;
	delete tileset;
}

void Enemy::Update() {
	animation->Select(state);
	animation->NextFrame();
}

void Enemy::OnCollision(Object* obj) {

}
