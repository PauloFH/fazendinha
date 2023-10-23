#include "Enemy.h"
#include "Fazendinha.h"
#include <sstream>

Enemy::Enemy() {
	tileset = new TileSet("Resources/bug1.png", 16, 16, 4, 17);
	animation = new Animation(tileset, 0.2f, true);

	uint enemyDown[4] = { 0, 1, 2, 3 };
	uint enemyRight[4] = { 4, 5, 6, 7 };
	uint enemyUp[4] = { 8, 9, 10, 11 };
	uint enemyLeft[4] = { 12, 13, 14, 15 };
	animation->Add(ENEMYDOWN, enemyDown, 4);
	animation->Add(ENEMYRIGHT, enemyRight, 4);
	animation->Add(ENEMYUP, enemyUp, 4);
	animation->Add(ENEMYLEFT, enemyLeft, 4);

	BBox(new Rect(-8, -8, 7, 7));

	speed.RotateTo(0);
	speed.ScaleTo(2.0f);

	Scale(2.0);

	MoveTo(Fazendinha::player->X(), Fazendinha::player->Y() - 200);

	timer.Start();

	type = ENEMY;

}

Enemy::~Enemy() {
	delete animation;
	delete tileset;
}

void Enemy::Update() {

	// Calcula as diferenças entre as coordenadas X e Y do inimigo e do jogador
	float deltaX = Fazendinha::player->X() - x;
	float deltaY = Fazendinha::player->Y() - y;

	// Calcula os valores absolutos das diferenças
	float absDeltaX = fabs(deltaX);
	float absDeltaY = fabs(deltaY);

	// Compara os valores absolutos e define o estado com base na maior diferença
	if (absDeltaX > absDeltaY) {
		// A diferença em X é maior, vire na direção X
		if (deltaX > 0) {
			state = ENEMYRIGHT;
		}
		else {
			state = ENEMYLEFT;
		}
	}
	else {
		// A diferença em Y é maior, vire na direção Y
		if (deltaY > 0) {
			state = ENEMYDOWN;
		}
		else {
			state = ENEMYUP;
		}
	}

	animation->Select(state);
	animation->NextFrame();

	speed.RotateTo(Line::Angle(Point(x, y), Point(Fazendinha::player->X(), Fazendinha::player->Y())));
	//RotateTo(Line::Angle(Point(x, y), Point(Fazendinha::player->X(), Fazendinha::player->Y())));

	// movimenta objeto pelo seu vetor velocidade
	Translate(speed.XComponent() * 50.0f * gameTime, -speed.YComponent() * 50.0f * gameTime);

	if (timer.Elapsed(2.0f)) {
		hit = true;
	}

}

void Enemy::OnCollision(Object* obj) {
	if (obj->Type() == PLAYER) {
		if (hit) {
			Fazendinha::player->vidas--;
			hit = false;
			std::stringstream text;

			text.str("");

			text << Fazendinha::player->vidas << ".\n";
			OutputDebugString(text.str().c_str());
			timer.Reset();
		}
	}
}
