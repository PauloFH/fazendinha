#include "Inventary.h"
#include "Fazendinha.h"

Inventary::Inventary() {
	sprite = new Sprite("Resources/inventario.png");
	spaces = new InventorySpace*[12];

	Scale(0.5);

	for (int i = 0; i < 12; i++) {
		spaces[i] = new InventorySpace();
	}

	for (int i = 0; i < 12; i++) {
		Fazendinha::scene->Add(spaces[i], STATIC);
	}

	spaces[0]->chave = '1';
	spaces[1]->chave = '2';
	spaces[2]->chave = '3';
	spaces[3]->chave = '4';
	spaces[4]->chave = '5';
	spaces[5]->chave = '6';
	spaces[6]->chave = '7';
	spaces[7]->chave = '8';
	spaces[8]->chave = '9';
	spaces[9]->chave = '0';
	spaces[10]->chave = 'K';
	spaces[11]->chave = 'L';

}

Inventary::~Inventary() {
	for (int i = 0; i < 12; i++) {
		Fazendinha::scene->Remove(spaces[i], STATIC);
	}
	delete[] spaces;
	delete sprite;
}

void Inventary::Update() {
	MoveTo(game->viewport.left + window->Width() / 2, game->viewport.top + window->Height() - sprite->Height() / 4);

	for (int i = 0; i < 12; i++) {
		if (spaces[i]->cont < 0) {
			spaces[i]->objItem = nullptr;
		}
	}

	spaces[0]->MoveTo(game->viewport.left + 232, game->viewport.top + window->Height() - 27);
	spaces[1]->MoveTo(game->viewport.left + 278, game->viewport.top + window->Height() - 27);
	spaces[2]->MoveTo(game->viewport.left + 324, game->viewport.top + window->Height() - 27);
	spaces[3]->MoveTo(game->viewport.left + 370, game->viewport.top + window->Height() - 27);
	spaces[4]->MoveTo(game->viewport.left + 416, game->viewport.top + window->Height() - 27);
	spaces[5]->MoveTo(game->viewport.left + 462, game->viewport.top + window->Height() - 27);
	spaces[6]->MoveTo(game->viewport.left + 508, game->viewport.top + window->Height() - 27);
	spaces[7]->MoveTo(game->viewport.left + 554, game->viewport.top + window->Height() - 27);
	spaces[8]->MoveTo(game->viewport.left + 600, game->viewport.top + window->Height() - 27);
	spaces[9]->MoveTo(game->viewport.left + 646, game->viewport.top + window->Height() - 27);
	spaces[10]->MoveTo(game->viewport.left + 692, game->viewport.top + window->Height() - 27);
	spaces[11]->MoveTo(game->viewport.left + 738, game->viewport.top + window->Height() - 27);

}

void Inventary::OnCollision(Object* obj) {

}
