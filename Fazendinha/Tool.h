#pragma once

#include "Object.h"
#include "Animation.h"
#include "Timer.h"

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

public:
	Tool();
	~Tool();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline void Tool::Draw() {
	animation->Draw(x, y, z, scale);
}
