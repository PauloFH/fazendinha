#include "TelaInicial.h"
#include "Fazendinha.h"

Audio* TelaInicial::audio = nullptr;
Scene* TelaInicial::scene = nullptr;

void TelaInicial::Init()
{
    // cria sistema de áudio
    audio = new Audio();
    audio->Add(THEME, "Resources/Theme.wav");
    audio->Add(FIRE, "Resources/Fire.wav");
    audio->Add(HITWALL, "Resources/Hitwall.wav");
    audio->Add(EXPLODE, "Resources/Explode.wav");
    audio->Add(START, "Resources/Start.wav");

    // ajusta volumes
    audio->Volume(FIRE, 0.2f);
    audio->Volume(START, 0.8f);
    audio->Play(START, true);

	scene = new Scene();
	background = new Background("Resources/telaInicial_bg.png");
	text = new Font("Resources/Stardew42.png");
	text->Spacing(190);
}

void TelaInicial::Update(){
	if (window->KeyDown(VK_ESCAPE)) {
		window->Close();
	}
	if (window->KeyDown('N') ){
		audio->Stop(START);
	}

}

void TelaInicial::Draw(){
	Color White(1.0f, 1.0f, 0.3f, 1.0f);
	text -> Draw(125, window->CenterY()-150, "Fazendinha", White, Layer::UPPER, 0.5f);

	background->Draw(viewport);
}

void TelaInicial::Finalize()
{
	delete background;
	delete audio;
	delete text;
	delete scene;
}

