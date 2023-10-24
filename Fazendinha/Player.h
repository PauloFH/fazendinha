/**********************************************************************************
// Player (Arquivo de Cabeçalho)
// 
// Criação:     10 Out 2012
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2022
//
// Descrição:   Define a classe jogador
//
**********************************************************************************/

#ifndef _PLAYER_H_
#define _PLAYER_H_

// ---------------------------------------------------------------------------------

#include "Object.h"                        // objetos do jogo
#include "Sprite.h"                        // desenho de sprites
#include "Vector.h"                        // representação de vetores
#include "Particles.h"                    // sistema de partículas
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
    Vector * speed;                     // velocidade e direção
    int vidas = 5;
    Item * usavel;

    Player();                           // construtor
    ~Player();                          // destrutor

    uint PlayerState();
    
    void Move(Vector && v);             // movimenta jogador
    void Update();                      // atualização
    void Draw();                        // desenho
}; 
// ---------------------------------------------------------------------------------

inline uint Player::PlayerState() {
    return state;
}

#endif
