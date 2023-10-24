#include "CraftMenu.h"
#include "Fazendinha.h"


bool CraftMenu::isOpen = false;
CraftMenu::CraftMenu() {
	sprite = new Sprite("Resources/craftmenu.png");
}

CraftMenu::~CraftMenu() {
	delete sprite;
}

void CraftMenu::Update() {
	if (isOpen) {
		sprite->Draw(game->viewport.left+window->Width()/2, game->viewport.top+window->Height()/2-100),Layer::UPPER;
	}
}

void CraftMenu::Draw() {
}

