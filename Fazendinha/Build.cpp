
/**********************************************************************************
// Build
//
// Descrição:   Objeto para setar construções com interação de entrada
//
**********************************************************************************/

#include "Build.h"
#include "Fazendinha.h"

Build::Build(int posx, int posy ,UINT id_, Sprite * s) {

	posX = posx;
	posY = posy;
	sprite = s;
	id = id_;
	if (id == HOME) {
		BBox(new Rect(-300, 100, 300, -200));
		Scale(2.0f);
	}
	if (id == COMMUNITY) {
		BBox(new Rect(-150, 50, 100, -100));	
	}
	if (id == SHOP_BUILD) {
		Scale(2.0f);
	}
	MoveTo(posX, posY);
}

Build::~Build(){
	delete sprite;
	
}

void Build::Update(){

}
 void Build::OnCollision(Object* obj){

}
void Build::Draw(){

	 sprite->Draw(x, y, Layer::LOWER, scale, rotation);
 }