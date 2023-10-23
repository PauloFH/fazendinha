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
	bool moving = false;

public:
	uint itemType;
	InventorySpace* space;
	bool considerado = false;

	Item(uint itType, InventorySpace* spc);
	~Item();

	void Draw();
	void Update();
	void OnCollision(Object* obj);

};
