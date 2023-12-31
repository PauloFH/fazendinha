#include "InventorySpace.h"
#include "Fazendinha.h"
#include <sstream>

InventorySpace::InventorySpace(bool loja) {

	isLoja = loja;

	BBox(new Rect(-16, -16, 15, 15));
	
	type = SPACE;

}

InventorySpace::~InventorySpace() {

}

void InventorySpace::Update() {
	ocupado = false;


	if (cont < 0) {
		Fazendinha::scene->Delete(objItem, MOVING);
	}
}

void InventorySpace::Draw() {
	Color White(1.0f, 1.0f, 1.0f, 5.0f);
	if (!ocupado) {
		cont = 0;
	}
	if (cont > 0) {
		string qtd = std::to_string(cont);
		Fazendinha::text->Draw(x - game->viewport.left + 16, y - game->viewport.top + 16, qtd, White, Layer::FRONT - 0.01, 0.12f);
	}
}

void InventorySpace::OnCollision(Object* obj) {
	std::stringstream text;

	if (obj->Type() == ITEM) {
		Item* item = dynamic_cast<Item*>(obj);

		if (!ocupado) {
			itemType = item->itemType;
		}
		else {
			objItem = item;
		}

		ocupado = true;

		if (!item->considerado && item->space == this) {
			cont++;
			item->considerado = true;
		}

		/* por algum motivo t� bugando e t� devolvendo o dinheiro sempre
		if (!item->aVenda) {
			Fazendinha::player->dinheiro += item->precoItem;
			item->aVenda = true;

			std::stringstream text;

			text.str("");

			text << Fazendinha::player->dinheiro << ".\n";
			OutputDebugString(text.str().c_str());
		}*/

	}
}
