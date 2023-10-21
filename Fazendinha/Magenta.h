/**********************************************************************************
// Magenta (Arquivo de Cabe�alho)
// 
// Cria��o:     10 Out 2012
// Atualiza��o: 01 Nov 2021
// Compilador:  Visual C++ 2022
//
// Descri��o:   Objeto faz um persegui��o direta
//
**********************************************************************************/

#ifndef _GEOWARS_MAGENTA_H_
#define _GEOWARS_MAGENTA_H_

// ---------------------------------------------------------------------------------

#include "Object.h"    
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

class Magenta : public Object
{
private:
    Sprite * sprite;                    // sprite do objeto
    Vector * speed;                     // velocidade e dire��o
    Player * player;                    // ponteiro para jogador
    
public:
    Magenta(Player * p);                // construtor
    ~Magenta();                         // destrutor
    
    void OnCollision(Object * obj);     // resolu��o da colis�o
    void Update();                      // atualiza��o
    void Draw();                        // desenho
}; 

// ---------------------------------------------------------------------------------

inline void Magenta::Draw()
{ sprite->Draw(x, y, Layer::LOWER, scale, rotation); }

// ---------------------------------------------------------------------------------


#endif