#pragma once

#include "Object.h"
#include "Sprite.h"
#include "BauSpaces.h"
#include "CraftMenu.h"

class Cookout : public Object 
{

private:
	CraftMenu* cm;
	Sprite* sprite;
	bool opened = false;

public:
	Cookout();
	~Cookout();

	void Draw();
	void Update();
	void OnCollision(Object* obj);

};

inline void Cookout::Draw() { sprite->Draw(x, y, z, scale); }
