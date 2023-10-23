
/**********************************************************************************
// Build 
//
// Descrição:   Objeto para setar construções com interação de entrada
//
**********************************************************************************/
#ifndef _BUILD_H_
#define _BUILD_H_

#include "Object.h"
#include "Sprite.h"

// ---------------------------------------------------------------------------------

class Build : public Object {
private:
	UINT id;
	Sprite* sprite;
	int posX;
	int posY;
	bool ocupado = false;
public:
	Build(int posX, int posY, UINT id, Sprite * s);
	~Build();
	void Update();
	void Draw();
	void OnCollision(Object* obj);
};


#endif
