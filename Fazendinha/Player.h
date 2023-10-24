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
#include "Vector.h"                        // representação de vetores
#include "Particles.h"                    // sistema de partículas
#include "Item.h"
#include "Animation.h"
#include "Sprite.h"

// ---------------------------------------------------------------------------------

enum playerState {
    NORMAL,
    HOLDING,
    TOOL,
    PLAYERLEFT,
    PLAYERRIGHT,
    PLAYERUP,
    PLAYERDOWN,
    NORMALLEFT,
    NORMALRIGHT,
    NORMALUP,
    NORMALDOWN
};

class Player : public Object
{
private:
    TileSet* tileset;
    Animation* animation;
    uint state = NORMAL;
    uint relaxState = NORMAL;
    Sprite* placarDinheiro;

public:
    int vel = 0;
    Vector * speed;                     // velocidade e direção
    int vidas = 5;
    Item * usavel;
    int dinheiro = 1000;

    Player();                           // construtor
    ~Player();                          // destrutor

    uint PlayerState();
    
    void Move(Vector && v);             // movimenta jogador
    void Update();                      // atualização
    void Draw();                        // desenho
    void OnCollision(Object* obj);
}; 
// ---------------------------------------------------------------------------------

inline uint Player::PlayerState() {
    return state;
}

#endif
