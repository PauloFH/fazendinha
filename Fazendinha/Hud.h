/**********************************************************************************
// Hud (Arquivo de Cabe�alho)
//
// Cria��o:     02 Ago 2019
// Atualiza��o: 01 Nov 2021
// Compilador:  Visual C++ 2022
//
// Descri��o:   Heads Up Display
//
**********************************************************************************/

#ifndef _GEOWARS_HUD_H_
#define _GEOWARS_HUD_H_

// --------------------------------------------------------------------------------

#include "Object.h"
#include "Sprite.h"
#include "Font.h"
#include <sstream>
using std::stringstream;

// --------------------------------------------------------------------------------

class Hud : public Object
{
private:
    Font * font = nullptr;              // fonte para exibi��o normal
    Font * bold = nullptr;              // fonte para exibi��o negrito
    Sprite * infoBox = nullptr;         // �rea de informa��es do jogo
    Sprite * keyMap = nullptr;          // �rea para teclas de comando
    stringstream text;                  // texto tempor�rio

public:
    Hud();                              // construtor
    ~Hud();                             // destrutor

    void Update();                      // atualiza��o
    void Draw();                        // desenho
};

// ------------------------------------------------------------------------------

#endif

