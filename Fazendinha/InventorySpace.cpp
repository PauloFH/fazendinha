#include "InventorySpace.h"
#include "Fazendinha.h"

InventorySpace::InventorySpace() {

	BBox(new Rect(-16, -16, 15, 15));
	
	type = SPACE;

}

InventorySpace::~InventorySpace() {

}

void InventorySpace::Update() {
	ocupado = false;
}

void InventorySpace::OnCollision(Object* obj) {
	if (obj->Type() == ITEM) {
		ocupado = true;
	}
}
