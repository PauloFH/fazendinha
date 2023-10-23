#pragma once

#include "Object.h"
#include "Font.h"

class InventorySpace : public Object {
private:

public:
	bool ocupado = false;
	uint itemType;
	int cont = 0;

	InventorySpace();
	~InventorySpace();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};
