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
	SEEDMELAO, 
	ITEMREGADOR
};

class Item : public Object {

private:

	Sprite* sprite;
	bool moving = false;

public:
	uint itemType;
	InventorySpace* space;
	bool considerado = false;
	bool pego = false;

	Item(uint itType = 0, InventorySpace* spc = nullptr);
	~Item();

	void Draw();
	void Update();
	void OnCollision(Object* obj);

};
