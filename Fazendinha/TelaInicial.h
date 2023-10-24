#pragma once

#include "Game.h"
#include "Scene.h"
#include "Background.h"
#include "Font.h"
#include "Scene.h"
#include "Audio.h"

enum SoundIds {THEME,START,FIRE,EXPLODE,HITWALL};

class TelaInicial : public Game {

private:
	Background* background = nullptr;
	Font* text = nullptr;

public:
	static Scene* scene;
	static Audio* audio;

	void Init();
	void Update();
	void Draw();
	void Finalize();
};
