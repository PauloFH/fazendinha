
#include "Object.h"
#include "Sprite.h"

class Ground : public Object {
private:

	Sprite* sprite;
	Sprite* normal;
	Sprite* arado;
	Sprite* molhado;
	int posX;
	int posY;
	bool ocupado = false;

public:
	bool isMolhado = false;

	int Height();
	int Width();

	Ground( int posX, int posY);
	~Ground();

	void Update();
	void Draw();
	void OnCollision(Object* obj);
};

inline int Ground::Height() {
	return sprite->Height();
}

inline int Ground::Width() {
	return sprite->Width();
}
