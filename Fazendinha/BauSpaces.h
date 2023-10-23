#pragma once

#include "Object.h"
#include "Sprite.h"
#include "InventorySpace.h"

class BauSpaces : public Object {

private:
	Sprite* sprite;
	int varX;
	int varY;	

public:
	InventorySpace** spaces;
	bool isOpen = false;

	BauSpaces();
	~BauSpaces();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline void BauSpaces::Draw() {

	sprite->Draw(x, y, Layer::FRONT + 0.01, scale);

}
