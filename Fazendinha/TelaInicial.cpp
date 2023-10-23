#include "TelaInicial.h"
#include "Fazendinha.h"

Scene* TelaInicial::scene = nullptr;

void TelaInicial::Init()
{
	scene = new Scene();
	background = new Background("Resources/telaInicial_bg.png");
	text = new Font("Resources/Tahoma14.png");
	text->Spacing(9.0f);
}

void TelaInicial::Update(){
	if (window->KeyDown(VK_ESCAPE)) {
		window->Close();
	}

}

void TelaInicial::Draw(){
	Color White(1.0f, 1.0f, 0.3f, 1.0f);
	text -> Draw(window->CenterX()-35, window->CenterY(), "8===D", White, Layer::UPPER, 5.f);

	background->Draw(viewport);
}

void TelaInicial::Finalize()
{
	delete background;
	delete text;
	delete scene;
}

