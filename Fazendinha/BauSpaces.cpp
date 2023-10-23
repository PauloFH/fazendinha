#include "BauSpaces.h"
#include "Fazendinha.h"
#include <sstream>

BauSpaces::BauSpaces() {
	sprite = new Sprite("Resources/bauEspacos.png");
	spaces = new InventorySpace * [36];

	for (int i = 0; i < 36; i++) {
		spaces[i] = new InventorySpace(); // Substitua `i` pelo valor desejado
	}

	for (int i = 0; i < 36; i++) {
		Fazendinha::scene->Add(spaces[i], STATIC);
	}

	varX = 232;
	varY = window->Height() / 2 - 43;

}

BauSpaces::~BauSpaces() {
	for (int i = 0; i < 36; i++) {
		Fazendinha::scene->Remove(spaces[i], STATIC);
	}
	delete[] spaces;
	delete sprite;
}

void BauSpaces::Update() {

	if (isOpen) {
		for (int i = 0; i <= 36; i++) {
			if (i == 36) {
				varX = 232;
				varY = window->Height() / 2 - 43;
			}
			else {
				spaces[i]->MoveTo(game->viewport.left + varX, game->viewport.top + varY);
				varX += 46;
				if ((i + 1) % 12 == 0) {
					varY += 49;
					varX = 232;
				}
			}
		}
	}
	else {
		for (int i = 0; i <= 36; i++) {
			if (i == 36) {
				varX = 100000;
				varY = 100000;
			}
			else {
				spaces[i]->MoveTo(game->viewport.left + varX, game->viewport.top + varY);
				varX += 46;
				if ((i + 1) % 12 == 0) {
					varY += 49;
					varX = 100000;
				}
			}
		}


		std::stringstream text;

		text.str("");

		text << "testee" << ".\n";
		OutputDebugString(text.str().c_str());
	}
	
}

void BauSpaces::OnCollision(Object* obj) {

}
