#include "Item.h"
#include "Fazendinha.h"
#include <sstream>

Item::Item(uint itType, InventorySpace* spc) {
	
	itemType = itType;
	space = spc;

	if (itemType == ITEMCHIRIVIA) {
		sprite = new Sprite("Resources/Items/chirivia.png");
	}
	else if (itemType == SEEDCHIRIVIA) {
		sprite = new Sprite("Resources/Items/seedChirivia.png");
	}

	if (itemType == ITEMCOUVEFLOR) {
		sprite = new Sprite("Resources/Items/couveflor.png");
	}
	else if (itemType == SEEDCOUVEFLOR) {
		sprite = new Sprite("Resources/Items/seedCouveflor.png");
	}

	if (itemType == ITEMBATATA) {
		sprite = new Sprite("Resources/Items/batata.png");
	}
	else if (itemType == SEEDBATATA) {
		sprite = new Sprite("Resources/Items/seedBatata.png");
	}

	if (itemType == ITEMABACAXI) {
		sprite = new Sprite("Resources/Items/abacaxi.png");
	}
	else if (itemType == SEEDABACAXI) {
		sprite = new Sprite("Resources/Items/seedAbacaxi.png");
	}

	if (itemType == ITEMABOBORA) {
		sprite = new Sprite("Resources/Items/abobora.png");
	}
	else if (itemType == SEEDABOBORA) {
		sprite = new Sprite("Resources/Items/seedAbobora.png");
	}

	if (itemType == ITEMMELAO) {
		sprite = new Sprite("Resources/Items/melao.png");
	}
	else if (itemType == SEEDMELAO) {
		sprite = new Sprite("Resources/Items/seedMelao.png");
	}

	if (itemType == ITEMMILHO) {
		sprite = new Sprite("Resources/Items/milho.png");
	}
	else if (itemType == SEEDMILHO) {
		sprite = new Sprite("Resources/Items/seedMilho.png");
	}

	if (itemType == ITEMBERINJELA) {
		sprite = new Sprite("Resources/Items/berinjela.png");
	}
	else if (itemType == SEEDBERINJELA) {
		sprite = new Sprite("Resources/Items/seedBerinjela.png");
	}

	if (itemType == ITEMREGADOR) {
		sprite = new Sprite("Resources/Items/regador.png");
	}

	if (itemType == ITEMARADOR) {
		sprite = new Sprite("Resources/Items/arador.png");
	}

	BBox(new Rect(-24, -24, 23, 23));

	type = ITEM;
}

Item::~Item() {
	delete sprite;
}

void Item::Update() {

	if (aVenda) {
		if (itemType == SEEDCHIRIVIA) {
			precoItem = 10;
		}
		else if (itemType == SEEDCOUVEFLOR) {
			precoItem = 15;
		}
		else if (itemType == SEEDMELAO) {
			precoItem = 25;
		}
		else if (itemType == SEEDBATATA) {
			precoItem = 40;
		}
		else if (itemType = SEEDBERINJELA) {
			precoItem = 50;
		}
		else if (itemType == SEEDABACAXI) {
			precoItem = 150;
		}
		else if (itemType == SEEDABOBORA) {
			precoItem = 80;
		}
		else if (itemType == SEEDMILHO) {
			precoItem = 30;
		}
	}

	if (pego) {
		//MoveTo(Fazendinha::player->X(), Fazendinha::player->Y() + 100);
		if (!moving && space != nullptr && space->X() != -10000) {
			MoveTo(space->X(), space->Y());
			space->ocupado = true;
		}
		if (space->X() == -10000) {
			space->ocupado = true;
		}
	}
	else {
		if (!moving && space != nullptr && space->X() != -10000) {
			MoveTo(space->X(), space->Y());
			space->ocupado = true;
		}
		if (space->X() == -10000) {
			space->ocupado = true;
		}
	}

}

void Item::Draw() {
	sprite->Draw(x, y, Layer::FRONT, scale);
}

void Item::OnCollision(Object* obj) {
	if (obj->Type() == MOUSE) {
		if (Fazendinha::player->dinheiro >= precoItem && !pego && !Fazendinha::mouse->carrying && window->KeyPress(VK_LBUTTON)) {
			Fazendinha::mouse->carrying = true;
			Fazendinha::mouse->itemHolded = this;
			if (Fazendinha::mouse->itemHolded->space != nullptr) {
				Fazendinha::mouse->itemHolded->space->cont--;
			}
			moving = true;
			if (aVenda) {
				Fazendinha::player->dinheiro = Fazendinha::player->dinheiro - precoItem;
				aVenda = false;
				std::stringstream text;

				text.str("");

				text << Fazendinha::player->dinheiro << ".\n";
				OutputDebugString(text.str().c_str());
			}
		}

		if (!pego && Fazendinha::mouse->carrying && Fazendinha::mouse->itemHolded == this && window->KeyPress(VK_LBUTTON)) {
			Fazendinha::mouse->carrying = false;
			Fazendinha::mouse->itemHolded->considerado = false;
			Fazendinha::mouse->itemHolded = nullptr;
			moving = false;
		}
	}

}