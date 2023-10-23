/**********************************************************************************
// 
(Arquivo de Cabeçalho)
// 
// Criação:     23 Out 2012
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2022
//
// Descrição:   Demonstração da versão final do motor
//
**********************************************************************************/

#ifndef _FAZENDINHA_H_
#define _FAZENDINHA_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Audio.h"
#include "Scene.h"
#include "Background.h"
#include "Player.h"
#include "Mouse.h"

// ------------------------------------------------------------------------------

enum ObjectIds { PLAYER, GROUND, GRASS, HOME, COMMUNITY, MISSILE, ANIMAL, PLANTATION, MOUSE, ITEM, BAU, SPACE};

// ------------------------------------------------------------------------------

enum SoundIds { THEME, START, FIRE, EXPLODE, HITWALL };

// ------------------------------------------------------------------------------

enum DayState { DAY, NIGHT };

// ------------------------------------------------------------------------------

class Fazendinha : public Game
{
private:
    Background * backg = nullptr;   // pano de fundo
    bool viewBBox = false;          // visualização das bouding boxes

public:
    static Player * player;         // nave controlada pela jogador
    static Audio * audio;           // sitema de áudio
    static Scene * scene;           // cena do jogo
    static bool viewHUD;            // visualização do painel
    static Timer timer;
    static uint dayState;
    static int dayCount;
    static Mouse * mouse;

    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização

 
};

// ---------------------------------------------------------------------------------

#endif