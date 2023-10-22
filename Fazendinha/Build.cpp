
/**********************************************************************************
// Build
//
// Descri��o:   Objeto para setar constru��es com intera��o de entrada
//
**********************************************************************************/

#include "Build.h"


Build::Build(int posx, int posy, Sprite* s, UINT id_) {

	posX = posx;
	posY = posy;
	sprite = s;
	id = id_;
	MoveTo(posX, posY);
}

Build::~Build(){
}

void Build::Update(){

}
 void Build::OnCollision(Object* obj){

}
void Build::Draw(){

	 sprite->Draw(x, y, Layer::BACK, scale, rotation);
 }