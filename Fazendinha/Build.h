
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
#include "BauSpaces.h"
#include "Item.h"

// ---------------------------------------------------------------------------------

class Build : public Object {
private:
	UINT id;
	Sprite* sprite;
	int posX;
	int posY;
	bool ocupado = false;
	Item* itemToAdd = nullptr;
public:
	BauSpaces* shopping;
	bool opened = false;

	Build(int posX, int posY, UINT id, Sprite * s);
	~Build();

	float Height();
	float Width();

	void Update();
	void Draw();
	void OnCollision(Object* obj);
};

inline float Build::Width() {
	return sprite->Width() * 0.4;
}

inline float Build::Height() {
	return sprite->Height() * 0.4;
}

#endif
