/**********************************************************************************
// Player (Arquivo de Cabe�alho)
// 
// Cria��o:     10 Out 2012
// Atualiza��o: 01 Nov 2021
// Compilador:  Visual C++ 2022
//
// Descri��o:   Define a classe jogador
//
**********************************************************************************/

#ifndef _PLAYER_H_
#define _PLAYER_H_

// ---------------------------------------------------------------------------------

#include "Object.h"                        // objetos do jogo
#include "Sprite.h"                        // desenho de sprites
#include "Vector.h"                        // representa��o de vetores
#include "Particles.h"                    // sistema de part�culas
#include "Item.h"
#include "Animation.h"

// ---------------------------------------------------------------------------------

enum playerState {
    NORMAL,
    HOLDING,
    TOOL
};

class Player : public Object
{
private:
    Sprite * sprite;                    // sprite do objeto
    TileSet* tileset;
    Animation* animation;
    uint state = NORMAL;

public:
    Vector * speed;                     // velocidade e dire��o
    int vidas = 5;
    Item * usavel;

    Player();                           // construtor
    ~Player();                          // destrutor

    uint PlayerState();
    
    void Move(Vector && v);             // movimenta jogador
    void Update();                      // atualiza��o
    void Draw();                        // desenho
}; 
// ---------------------------------------------------------------------------------

inline uint Player::PlayerState() {
    return state;
}

#endif
