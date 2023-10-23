#pragma once

#include "Object.h"
#include "Sprite.h"
#include "InventorySpace.h"

enum ItemTypes {
	ITEMCHIRIVIA,
	SEEDCHIRIVIA,
	ITEMCOUVEFLOR,
	SEEDCOUVEFLOR,
	ITEMMELAO,
	SEEDMELAO
};

class Item : public Object {

private:

	Sprite* sprite;
	uint itemType;
	bool moving = false;

public:
	InventorySpace* space;

	Item(uint itType, InventorySpace* spc);
	~Item();

	void Draw();
	void Update();
	void OnCollision(Object* obj);

};
