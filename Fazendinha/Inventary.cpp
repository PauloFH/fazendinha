#include "Inventary.h"
#include "Fazendinha.h"

Inventary::Inventary() {
	sprite = new Sprite("Resources/inventario.png");
	spaces = new InventorySpace*[12];

	Scale(0.5);

	for (int i = 0; i < 12; i++) {
		spaces[i] = new InventorySpace(); // Substitua `i` pelo valor desejado
	}

	for (int i = 0; i < 12; i++) {
		Fazendinha::scene->Add(spaces[i], STATIC);
	}

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
