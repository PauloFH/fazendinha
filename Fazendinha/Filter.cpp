#include "Filter.h"
#include "Fazendinha.h"

bool Filter::activated = false;
Filter::Filter() {

	sprite = new Sprite("Resources/filter.png");

	cor = Color(0.11, 0.102, 0.239, 0.5f);

	// noite Color(0.11, 0.102, 0.239, 0.5f);

	Scale(2.0);

	activated = false;
}

Filter::~Filter() {
	delete sprite;
}

void Filter::Update() {

	MoveTo(Fazendinha::player->X(), Fazendinha::player->Y());
}