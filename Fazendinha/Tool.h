#pragma once

#include "Object.h"
#include "Animation.h"
#include "Timer.h"
#include "Particles.h"

enum ToolStates {
	TOOLFRONT,
	TOOLSIDE,
	TOOLANOTHERSIDE
};

class Tool : public Object {

private:
	TileSet* tileset;
	Animation* animation;
	Timer timer;
	Particles* agua;

public:
	uint state = TOOLFRONT;

	Tool(uint tipo = 15);
	~Tool();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

