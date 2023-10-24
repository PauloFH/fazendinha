#pragma once

#include "Object.h"
#include "Animation.h"

enum VendaState {
	CLOSED,
	OPENING,
	CLOSING
};

class Venda : public Object {

private:
	TileSet* tileset;
	Animation* animation;

public:
	uint state = CLOSED;
	bool open = false;

	Venda();
	~Venda();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline void Venda::Draw() {
	animation->Draw(x, y, z, scale);
}