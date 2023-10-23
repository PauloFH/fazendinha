#pragma once

#include "Object.h"
#include "Sprite.h"
#include "BauSpaces.h"
#include "CraftMenu.h"

class Cookout : public Object 
{

private:
	Sprite* sprite;
	CraftMenu* craftMenu;
	Cookout* ck;
	bool hit = false;

public:
	Cookout();
	~Cookout();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline void Cookout::Draw() { sprite->Draw(x, y, z, scale); }
