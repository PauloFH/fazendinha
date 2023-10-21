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
#include "Hud.h"

// ------------------------------------------------------------------------------

enum ObjectIds { PLAYER, MISSILE, BLUE, GREEN, MAGENTA, ORANGE, WALLHIT , GROUND, GRASS};

// ------------------------------------------------------------------------------

enum SoundIds { THEME, START, FIRE, EXPLODE, HITWALL };

// ------------------------------------------------------------------------------

class Fazendinha : public Game
{
private:
    Background * backg = nullptr;   // pano de fundo
    Hud * hud = nullptr;            // painel de informa��es
    bool viewBBox = false;          // visualiza��o das bouding boxes

public:
    static Player * player;         // nave controlada pela jogador
    static Audio * audio;           // sitema de �udio
    static Scene * scene;           // cena do jogo
    static bool viewHUD;            // visualiza��o do painel

    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o

 
};

// ---------------------------------------------------------------------------------

#endif