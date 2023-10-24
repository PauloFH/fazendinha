#include "CouveflorQueijo.h"
#include "Fazendinha.h"
#include "CraftMenu.h"
#include "InventorySpace.h"
#include "Inventary.h"

CouveflorQueijo::CouveflorQueijo() {
	MoveTo(Fazendinha::player->X() + 95, Fazendinha::player->Y() - 90); // Trocar p/ viewport
	BBox(new Rect(-10,-15,10,5) );
	Scale(2.0);
}

void CouveflorQueijo::OnCollision(Object* obj) {
	if (obj->Type() == MOUSE){
		if (CraftMenu::isOpen == true && window->KeyPress(VK_LBUTTON)) {

			//verificar se possui os items
			/*
			for (int i = 0; i < 12; i++) {
				InventorySpace** space = new InventorySpace * [12];
            }*/
		}
	}
	
}

void CouveflorQueijo::Update() {
	
	//MoveTo(game->viewport.left + 385, game->viewport.top + 250); ESQUERDA - OMELETE
	//MoveTo(game->viewport.left + 485, game->viewport.top + 250); MEIO
	MoveTo(game->viewport.left + 580, game->viewport.top + 250); 
}

CouveflorQueijo::~CouveflorQueijo(){ }

