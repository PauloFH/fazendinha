
#include "Object.h"
#include "Sprite.h"

class Ground : public Object {
private:

	Sprite* sprite;
	Sprite* normal;
	Sprite* molhado;
	int posX;
	int posY;
	bool ocupado = false;
	bool isMolhado = false;

public:

	int Height();
	int Width();

	Ground( int posX, int posY, bool toPut = false);
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
