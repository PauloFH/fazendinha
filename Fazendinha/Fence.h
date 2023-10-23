
#include "Object.h"
#include "Sprite.h"

enum fances
{
	FENCE_UP,
};
class Fence : public Object {
private:
	Sprite* sprite;
public:
	Fence(Geometry * b, UINT t, float x_, float y_);
	~Fence();
	void Update();
	void Draw();
	void OnCollision(Object* obj);
};