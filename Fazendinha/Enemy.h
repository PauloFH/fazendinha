#pragma once

#include "Object.h"
#include "Animation.h"

enum EnemyState {
	ENEMYLEFT,
	ENEMYRIGHT,
	ENEMYUP,
	ENEMYDOWN
};

class Enemy : public Object {

private:
	TileSet* tileset;
	Animation* animation;
	uint state = ENEMYLEFT;

public:
	Enemy();
	~Enemy();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline void Enemy::Draw() {
	animation->Draw(x, y, z, scale);
}
