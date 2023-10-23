#pragma once

#include "Object.h"
#include "Sprite.h"

class CraftMenu : public Object {
private:
	Sprite* sprite;

public:
	CraftMenu();
	~CraftMenu();

	void Draw();
	void Update();
};

inline void CraftMenu::Draw() { sprite->Draw(x,y, Layer::MIDDLE); }