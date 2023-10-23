#pragma once

#include "Object.h"
#include "Sprite.h"
#include "BauSpaces.h"

class Bau : public Object {

private:
	Sprite* sprite;
	bool opened = false;

public:
	BauSpaces* bauOpened;

	Bau();
	~Bau();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline void Bau::Draw() {
	sprite->Draw(x, y, z, scale);
}
