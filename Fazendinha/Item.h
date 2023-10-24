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
	ITEMREGADOR,
	ITEMARADOR
};

class Item : public Object {

private:

	Sprite* sprite;

public:
	uint itemType;
	InventorySpace* space;
	bool considerado = false;
	bool pego = false;
	bool moving = false;

	Item(uint itType = 0, InventorySpace* spc = nullptr);
	~Item();

	void Draw();
	void Update();
	void OnCollision(Object* obj);

};
