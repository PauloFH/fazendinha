#include "BauSpaces.h"
#include "Fazendinha.h"
#include <sstream>

BauSpaces::BauSpaces(bool loja) {

	isLoja = loja;

	sprite = new Sprite("Resources/bauEspacos.png");
	spaces = new InventorySpace * [36];

	for (int i = 0; i < 36; i++) {
		spaces[i] = new InventorySpace(isLoja); // se for loja, cria éspaços de loja. se não for, continua normal
	}

	for (int i = 0; i < 36; i++) {
		Fazendinha::scene->Add(spaces[i], STATIC);
	}

	varX = 232;
	varY = window->Height() / 2 - 43;

	MoveTo(100000, 100000);

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
		Fazendinha::player->vel = 0;
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
		Fazendinha::player->vel = 250;
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

	}
	
}

void BauSpaces::OnCollision(Object* obj) {

}
