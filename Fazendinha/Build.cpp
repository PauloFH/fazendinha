
/**********************************************************************************
// Build
//
// Descrição:   Objeto para setar construções com interação de entrada
//
**********************************************************************************/

#include "Build.h"
#include "Fazendinha.h"
#include "BauSpaces.h"

Build::Build(int posx, int posy ,UINT id_, Sprite * s) {

	posX = posx;
	posY = posy;
	sprite = s;
	id = id_;
	if (id == HOME) {
		Point vertex[7] = { Point(-72,1),Point(-72,-30),Point(-72,-30), Point(15,-74), Point(45,-70),Point(58,-40), Point(58,1) };

		Mixed* mixed = new Mixed();
		mixed->Insert(new Rect(-71, 1, 58, 40));
		mixed->Insert(new Rect(-71, 55, -10,68));
		mixed->Insert(new Rect(40,55, 57, 68));
		mixed->Insert(new Rect(58, -25, 72, 68));
		mixed->Insert(new Rect(-71, 40, -70, 58));
		mixed->Insert(new Poly(vertex, 7));
		BBox(mixed);
		type = HOME;
		
		Scale(2.0f);
	}
	if (id == COMMUNITY) {
		Point vertex[4] = { Point(-72,-130),Point(-5,-198),Point(8,-198), Point(80,-130)};

		Mixed* mixed = new Mixed();
		mixed->Insert(new Rect(-233, -130, 233, 195));
		mixed->Insert(new Poly(vertex, 4));
		BBox(mixed);

		type = COMMUNITY;
			
	}
	if (id == SHOP_BUILD) {
		Point vertex[5] = { Point(-49,10), Point(-30,-51),Point(0,-68) ,Point(33,-49),Point(46,10)};

		Mixed* mixed = new Mixed();
		mixed->Insert(new Rect(-31, -4, 31, 63));
		mixed->Insert(new Poly(vertex, 5));
		BBox(mixed);
		type = SHOP_BUILD;
		Scale(2.0f);
	}
	MoveTo(posX, posY);
}

Build::~Build(){
	delete sprite;
	
}

void Build::Update(){

	if (opened) {
		if (window->KeyPress(VK_RBUTTON)) {
			opened = false;
			shopping->isOpen = false;
			shopping->MoveTo(200000, 200000);
		}
	}

}


 void Build::OnCollision(Object* obj){
	 if (obj->Type() == MOUSE && this->type == SHOP_BUILD) {
		 if (!opened && window->KeyPress(VK_LBUTTON)) {
			 shopping = new BauSpaces();
			 shopping->isOpen = true;
			 Fazendinha::scene->Add(shopping, STATIC);
			 shopping->MoveTo(game->viewport.left + window->Width() / 2, game->viewport.top + window->Height() / 2);
			 for (int i = 0; i < 99; i++) {
				 itemToAdd = new Item(SEEDCHIRIVIA, shopping->spaces[0]);
				 Fazendinha::scene->Add(itemToAdd, MOVING);
			 }
			 opened = true;
		 }
	 }
}
void Build::Draw(){

	 sprite->Draw(x, y, Layer::LOWER, scale, rotation);
 }