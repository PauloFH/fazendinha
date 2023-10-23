#pragma once

#include "Game.h"
#include "Scene.h"
#include "Background.h"
#include "Font.h"
#include "Scene.h"

class TelaInicial : public Game {

private:
	Background* background = nullptr;
	Font* text = nullptr;

public:
	static Scene* scene;

	void Init();
	void Update();
	void Draw();
	void Finalize();
};
