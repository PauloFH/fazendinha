#pragma once

#include "Object.h"
#include "Animation.h"
#include "Timer.h"
#include "Particles.h"

enum ToolStates {
	TOOLFRONT,
	TOOLSIDE
};

class Tool : public Object {

private:
	TileSet* tileset;
	Animation* animation;
	uint state = TOOLFRONT;
	Timer timer;
	Particles* agua;

public:
	Tool(uint tipo = 15);
	~Tool();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

