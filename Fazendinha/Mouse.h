#pragma once

#include "Object.h"
#include "Item.h"

enum MouseState {
	PLENO,
	COLISAO
};

class Mouse : public Object {
private:

public:
	static uint state;
	static bool carrying;
	Item* itemHolded;

	uint State();

	Mouse();
	~Mouse();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline void Mouse::Draw() {

}

inline uint Mouse::State() {
	return state;
}