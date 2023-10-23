#pragma once

#include "Object.h"
#include "Sprite.h"
#include "InventorySpace.h"

class Inventary : public Object {
private:
	Sprite* sprite;

public:
	InventorySpace** spaces;

	Inventary();
	~Inventary();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline void Inventary::Draw() {
	sprite->Draw(game->viewport.left + window->Width() / 2, game->viewport.top + window->Height() - sprite->Height() / 4, Layer::FRONT + 0.01, scale); // +0.01 não deixa totalmente na frente
}
