#pragma once

#include "Object.h"
#include "Font.h"

class InventorySpace : public Object {
private:

public:
	bool ocupado = false;
	uint itemType;
	int cont = 0;
	char chave;
	Object* objItem;
	bool isLoja;

	InventorySpace(bool loja = false);
	~InventorySpace();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};
