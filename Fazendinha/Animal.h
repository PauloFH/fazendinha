#pragma once

#include "Object.h"
#include "Animation.h"

enum AnimalType {
	CHICKEN,
	COW,
	SHEEP
};

enum AnimalState {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Animal : public Object {
private:
	TileSet* tileset;
	Animation* animation;
	uint animalType;
	uint state = LEFT;
	Timer timer;
	int vel = 0;
	bool movable = false;
	uint nextState = LEFT;

public:

	Animal(uint anType);
	~Animal();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline void Animal::Draw() {
	animation->Draw(x, y, Layer::MIDDLE, scale, rotation);
}
