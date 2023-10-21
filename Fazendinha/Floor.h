
#include "Object.h"
#include "Sprite.h"
enum ObjectType {
	ENEMY,
	TOWER,
	DIRECTIONPOINT,
	POWERGREEN,
	POWERYELLOW,
	POWERRED,
	POWERBLUE,
	POWERPURPLE,
	FLOOR,
	MOUSE,
	FLOORSPACE,
	TOWERGREEN,
	TOWERBLUE,
	BUTTON,
	PRIEST,
	HUB,
	GRASS
};
class Floor : public Object {
private:

	Sprite* sprite;
	int posX;
	int posY;
	bool ocupado = false;

public:

	int Height();
	int Width();

	Floor( int posX, int posY, bool toPut = false);
	~Floor();

	void Update();
	void Draw();
	void OnCollision(Object* obj);
};

inline int Floor::Height() {
	return sprite->Height();
}

inline int Floor::Width() {
	return sprite->Width();
}
