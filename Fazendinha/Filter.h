#pragma once

#include "Object.h"
#include "Sprite.h"

class Filter : public Object {

private:
	Sprite* sprite;
	Color cor;

public:
	static bool activated;
	Filter();
	~Filter();

	void Draw();
	void Update();
};

inline void Filter::Draw() {
	if (activated) {
		sprite->Draw(x, y, Layer::UPPER, scale, 0.0f, cor);
	}
}
