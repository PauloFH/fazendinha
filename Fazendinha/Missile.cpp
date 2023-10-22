/**********************************************************************************
// Missile (C�digo Fonte)
// 
// Cria��o:     23 Nov 2011
// Atualiza��o: 01 Nov 2021
// Compilador:  Visual C++ 2022
//
// Descri��o:   Define uma classe para um m�ssil
//
**********************************************************************************/

#include "Missile.h"
#include "Fazendinha.h"

// ------------------------------------------------------------------------------

Player* & Missile::player = Fazendinha::player;        // refer�ncia para o player

// ------------------------------------------------------------------------------

Missile::Missile()
{
    // inicializa sprite
    sprite = new Sprite("Resources/Missile.png");

    // cria bounding box
    BBox(new Circle(8));
    
    // inicializa velocidade
    speed.RotateTo(player->speed->Angle());
    speed.ScaleTo(15.0f);
    
    // move para posi��o
    MoveTo(player->X() + 22 * cos(speed.Radians()), player->Y() - 22 * sin(speed.Radians()));
    RotateTo(-player->speed->Angle() + 90.0f);

    // define tipo
    type = MISSILE;
}

// ------------------------------------------------------------------------------

Missile::~Missile()
{
    delete sprite;
}

// -------------------------------------------------------------------------------

void Missile::Update()
{
    // move m�ssel com vetor resultante
    Translate(speed.XComponent() * 90.0f * gameTime, -speed.YComponent() * 90.0f * gameTime);

    // remove m�ssil da cena se ele sair da �rea de jogo
    if (x > game->Width() - 50 || x < 50 || y > game->Height() - 50 || y < 50)
    {
        // volume do som de destrui��o depende da dist�ncia para o jogador
        float distance = Point::Distance(Point(x, y), Point(player->X(), player->Y()));
        float level = (MaxDistance - distance) / MaxDistance * BaseVolume;
        Fazendinha::audio->Volume(HITWALL, level);
        Fazendinha::audio->Play(HITWALL);


        // remove m�ssil da cena
        Fazendinha::scene->Delete();
    }
}

// -------------------------------------------------------------------------------
