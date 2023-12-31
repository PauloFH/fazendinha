#include "Plantation.h"
#include "Fazendinha.h"
#include "Ground.h"

Plantation::Plantation(uint plant = CHIRIVIA) {

	initialDay = Fazendinha::dayCount;

	plantationType = plant;
	plantationState = GROWING;

	if (plantationType == CHIRIVIA) {
		numStages = 6;
		tileset = new TileSet("Resources/chirivia.png", 16, 32, numStages, numStages);
	}
	else if (plantationType == COUVEFLOR) {
		numStages = 7;
		tileset = new TileSet("Resources/couve-flor.png", 16, 32, numStages, numStages);
	}
	else if (plantationType == MELAO) {
		numStages = 7;
		tileset = new TileSet("Resources/melao.png", 16, 32, numStages, numStages);
	}
	else if (plantationType == BERINJELA) {
		numStages = 7;
		tileset = new TileSet("Resources/berinjela.png", 16, 32, numStages, numStages);
	}
	else if (plantationType == MILHO) {
		numStages = 7;
		tileset = new TileSet("Resources/milho.png", 16, 32, numStages, numStages);
	}
	else if (plantationType == ABOBORA) {
		numStages = 7;
		tileset = new TileSet("Resources/abobora.png", 16, 32, numStages, numStages);
	}
	else if (plantationType == ABACAXI) {
		numStages = 7;
		tileset = new TileSet("Resources/abacaxi.png", 16, 32, numStages, numStages);
	}
	else if (plantationType == BATATA) {
		numStages = 7;
		tileset = new TileSet("Resources/batata.png", 16, 32, numStages, numStages);
	}

	animation = new Animation(tileset, 0.5f, true);

	BBox(new Rect(-6, 1, 5, 11));
	Scale(2.0);
	MoveTo(Fazendinha::player->X(), Fazendinha::player->Y() + 100);

	timer.Start();
	
	type = PLANTATION;

}

Plantation::~Plantation() {
	delete tileset;
	delete animation;
}

void Plantation::Update() {

	if (animation->Frame() == numStages - 1) {
		plantationState = MATURE;
	}
	else if(timer.Elapsed(10.0f) && regada) {
		animation->NextFrame();
		regada = false;
		cresceu = true;
	}
	
	if (timer.Elapsed(0.0001f)) {
		if (objGround == nullptr) {
			Fazendinha::scene->Delete();
		}
	}

}

void Plantation::OnCollision(Object* obj) {
	if (obj->Type() == MOUSE) {
		if (plantationState == MATURE && window->KeyPress(VK_LBUTTON)) {
			InventorySpace* tst = new InventorySpace();
			tst->MoveTo(-10000, -10000);
			Item* fruto = new Item(plantationType, tst);
			Fazendinha::scene->Add(fruto, MOVING);
			fruto->MoveTo(x - 4, y - 4);

			Fazendinha::scene->Delete(this, MOVING);
		}
	}

}