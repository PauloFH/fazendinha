#pragma once

#include "Object.h"
#include "Animation.h"

enum PlantationType {
	CHIRIVIA,
	COUVEFLOR
};

enum PlantationState {
	GROWING,
	MATURE
};

class Plantation : public Object {

private:
	TileSet* tileset;
	Animation* animation;
	uint plantationType;
	uint plantationState;
	int numStages = 8;
	int stage = 0;
	int initialDay;

public:
	Plantation(uint plant);
	~Plantation();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline void Plantation::Draw() {
	animation->Draw(x, y, Layer::MIDDLE, scale);
}