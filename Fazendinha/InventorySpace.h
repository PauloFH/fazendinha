#pragma once

#include "Object.h"

class InventorySpace : public Object {
private:

public:
	bool ocupado = false;

	InventorySpace();
	~InventorySpace();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline void InventorySpace::Draw() {

}
