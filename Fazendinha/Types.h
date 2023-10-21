/**********************************************************************************
// Types (Arquivo de Cabe�alho)
// 
// Cria��o:     02 Abr 2011
// Atualiza��o: 04 Ago 2021
// Compilador:  Visual C++ 2022
//
// Descri��o:   Isola os tipos espec�ficos da plataforma fornecendo tipos
//              consistentes para o Motor de Jogo.
//
**********************************************************************************/

#ifndef _PROGJOGOS_TYPES_H_
#define _PROGJOGOS_TYPES_H_

// nomes para tipos padr�es da linguagem C++ usados na engine
using uchar  = unsigned char;
using ushort = unsigned short;
using ulong  = unsigned long;
using llong  = long long;
using ullong = unsigned long long;
using uint   = unsigned int;

struct Canvas
{
    float width;        // largura da �rea do jogo
    float height;       // altura da �rea do jogo
    float centerX;      // centro da �rea do jogo no eixo x
    float centerY;      // centro da �rea do jogo no eixo y
};

struct ViewPort
{
    float left;         // coordenada x1
    float top;          // coordenada y1
    float right;        // coordenada x2
    float bottom;       // coordenada y2
};

#endif