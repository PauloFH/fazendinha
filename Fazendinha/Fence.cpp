#include "Fence.h"
#include "Fazendinha.h"


Fence::Fence(Geometry * b_, UINT t, float x_, float y_)
{	
	type = FENCE;
	BBox(b_);
	
}

Fence::~Fence()
{

}

void Fence::Update()
{
}

void Fence::Draw()
{
}

void Fence::OnCollision(Object* obj)
{
}
