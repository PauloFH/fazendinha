#pragma once

#include "Object.h"
#include "Sprite.h"


class CraftMenu : public Object {

public:
	Sprite* sprite;
	CraftMenu();
	~CraftMenu();
	static bool isOpen;

	void Draw();
	void Update();
};


