#include "CraftMenu.h"
#include "Fazendinha.h"


CraftMenu::CraftMenu() {
	sprite = new Sprite("Resources/craftmenu.png");
	MoveTo(window->CenterX(), window->CenterY());
}

CraftMenu::~CraftMenu() {
	delete sprite;
}

void CraftMenu::Update() {
	MoveTo(window->CenterX(), window->CenterY());
}

