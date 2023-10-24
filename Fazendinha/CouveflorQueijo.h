#pragma once
#include "Object.h"
#include "Sprite.h"

class CouveflorQueijo : public Object {
public:
	CouveflorQueijo();
	~CouveflorQueijo();

	void OnCollision(Object* obj);
	void Update();
	void Draw();
	
private:
	Sprite* sprite = new Sprite("Resources/cookout_kit.png");
};

inline void CouveflorQueijo::Draw() { sprite->Draw(x, y, z, scale); }
