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
#include "Inventary.h"
#include "Controller.h"

// ------------------------------------------------------------------------------


enum ObjectIds { PLAYER, GROUND, GRASS, HOME, COMMUNITY, MISSILE, ANIMAL, PLANTATION, MOUSE, ITEM, BAU, SPACE, ENEMY, FENCE, SHOP_BUILD, REGADOR, ARADOR};

// ------------------------------------------------------------------------------

enum SoundIds { THEME, START,COW_AUDIO, GALINHA, ALEATORIO , CAVAR_AUDIO, AGUA_AUDIO, PLANTAR_AUDIO};

// ------------------------------------------------------------------------------

enum DayState { DAY, NIGHT };

// ------------------------------------------------------------------------------

class Fazendinha : public Game
{
private:
    Background * backg = nullptr;   // pano de fundo
    bool viewBBox = true;          // visualização das bouding boxes
    int tempo = 800;
public:
    static Controller* gamepad;
    static Player * player;         // nave controlada pela jogador
    static Audio * audio;           // sitema de áudio
    static Scene * scene;           // cena do jogo
    static bool viewHUD;            // visualização do painel
    static Timer timer;
    static uint dayState;
    static int dayCount;
    static Mouse * mouse;
    static Font * text;
    static Inventary * inventary;
    static bool controllerOn;          // controle directinput ativado
    static bool xboxOn;                // controle xinput ativado
    uint xboxPlayer = PLAYER1;          // controle Xbox ativo           
    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização

 
};

// ---------------------------------------------------------------------------------

#endif