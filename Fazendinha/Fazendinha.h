/**********************************************************************************
// 
(Arquivo de Cabe�alho)
// 
// Cria��o:     23 Out 2012
// Atualiza��o: 01 Nov 2021
// Compilador:  Visual C++ 2022
//
// Descri��o:   Demonstra��o da vers�o final do motor
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
    bool viewBBox = false;          // visualiza��o das bouding boxes

public:
    static Player * player;         // nave controlada pela jogador
    static Audio * audio;           // sitema de �udio
    static Scene * scene;           // cena do jogo
    static bool viewHUD;            // visualiza��o do painel
    static Timer timer;
    static uint dayState;
    static int dayCount;
    static Mouse * mouse;

    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o

 
};

// ---------------------------------------------------------------------------------

#endif