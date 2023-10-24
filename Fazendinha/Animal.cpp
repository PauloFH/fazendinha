#include "Animal.h"
#include "Fazendinha.h"

Animal::Animal(uint anType = 0) {

	animalType = anType;

	if (animalType == CHICKEN) {
		tileset = new TileSet("Resources/galinha.png", 16, 16, 4, 28);

		uint left[4] = { 12, 13, 14, 15 };
		uint right[4] = { 4, 5, 6, 7 };
		uint up[4] = { 8, 9, 10, 11 };
		uint down[4] = { 0, 1, 2, 3 };

		animation = new Animation(tileset, 0.2, true);
		animation->Add(LEFT, left, 4);
		animation->Add(RIGHT, right, 4);
		animation->Add(UP, up, 4);
		animation->Add(DOWN, down, 4);

		BBox(new Rect(-8, -8, 7, 7));

		Scale(1.8);
	}
	else if (animalType == COW) {
		tileset = new TileSet("Resources/vaca.png", 32, 32, 4, 24);

		uint left[4] = { 23, 22, 21, 20 };
		uint right[4] = { 4, 5, 6, 7 };
		uint up[4] = { 8, 9, 10, 11 };
		uint down[4] = { 0, 1, 2, 3 };

		animation = new Animation(tileset, 0.2, true);
		animation->Add(LEFT, left, 4);
		animation->Add(RIGHT, right, 4);
		animation->Add(UP, up, 4);
		animation->Add(DOWN, down, 4);

		BBox(new Rect(-16, -16, 15, 15));

		Scale(1.9);
	}
	vel = 50;
	timer.Start();
	recursoTimer.Start();

	MoveTo(Fazendinha::player->X() + 150, Fazendinha::player->Y() + 100);

	type = ANIMAL;

}

Animal::~Animal() {
	delete tileset;
	delete animation;
}

void Animal::Update() {

	RandI newState{ 0, 3 };


	if (animalType == CHICKEN && recursoTimer.Elapsed(600.0f)) {
		InventorySpace* tst = new InventorySpace();
		tst->MoveTo(-15000, -15000);
		Item* ovo = new Item(OVO, tst);
		Fazendinha::scene->Add(ovo, MOVING);
		ovo->MoveTo(x, y);
		recursoTimer.Reset();
	}

	if (animalType == COW && recursoTimer.Elapsed(600.0f)) {
		InventorySpace* tst = new InventorySpace();
		tst->MoveTo(-15000, -15000);
		Item* leite = new Item(LEITE, tst);
		Fazendinha::scene->Add(leite, MOVING);
		leite->MoveTo(x, y);
		recursoTimer.Reset();
	}

	if (timer.Elapsed(5.0f)) {
		movable = true;
		state = nextState;
	}

	if (movable) {
		if (state == LEFT) {
			Translate(-vel * gameTime, 0);
		}
		else if (state == RIGHT) {
			Translate(vel * gameTime, 0);
		}
		else if (state == UP) {
			Translate(0, -vel * gameTime);
		}
		else if (state == DOWN) {
			Translate(0, vel * gameTime);
		}

		if (timer.Elapsed(7.5f)) {
			timer.Reset();
			movable = false;
			nextState = newState.Rand();
		}

		animation->NextFrame();

	}
	else {
		if (animalType == CHICKEN) {
			state = DOWN;
		}
		animation->Frame(0);
	}

	animation->Select(state);

}

void Animal::OnCollision(Object* obj) {
	
	/*if (obj->Type() != ANIMAL) {
		movable = false;
		timer.Reset();
		esse if faz com que o animal não se mexa mais pq vai ficar pra sempre em colisão com o objeto
	}*/
}
