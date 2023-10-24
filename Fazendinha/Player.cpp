/**********************************************************************************
// Player (C�digo Fonte)
// 
// Cria��o:     10 Out 2012
// Atualiza��o: 01 Nov 2021
// Compilador:  Visual C++ 2022
//
// Descri��o:   Define a classe jogador
//
**********************************************************************************/

#include "Player.h" 
#include "Missile.h"
#include "Fazendinha.h"
#include "TelaInicial.h"
#include "Tool.h"

// -------------------------------------------------------------------------------

Player::Player()
{
    // configura��o do objeto
    sprite = new Sprite("Resources/Player.png");
    speed  = new Vector(90.0f, 0.0f);
    BBox(new Circle(18.0f));
    MoveTo(500, 600);
   // MoveTo(game->CenterX(), game->CenterY());
    type = PLAYER;

}

// -------------------------------------------------------------------------------

Player::~Player()
{
    delete sprite;
    delete speed;
}

// -------------------------------------------------------------------------------

void Player::Move(Vector && v)
{
    speed->Add(v);

    // limita velocidade m�xima
    if (speed->Magnitude() > 10.0f)
        speed->ScaleTo(10.0f);

}

// -------------------------------------------------------------------------------

void Player::Update()
{
    // magnitude do vetor acelera��o
    float accel = 40.0f * gameTime;

    // modifica vetor velocidade do player
    if (window->KeyDown(VK_RIGHT) && window->KeyDown(VK_UP))
        Move(Vector(45.0f, accel));
    else if (window->KeyDown(VK_LEFT) && window->KeyDown(VK_UP))
        Move(Vector(135.0f, accel));
    else if (window->KeyDown(VK_LEFT) && window->KeyDown(VK_DOWN))
        Move(Vector(225.0f, accel));
    else if (window->KeyDown(VK_RIGHT) && window->KeyDown(VK_DOWN))
        Move(Vector(315.0f, accel));
    else if (window->KeyDown(VK_RIGHT))
        Move(Vector(0.0f, accel));
    else if (window->KeyDown(VK_LEFT))
        Move(Vector(180.0f, accel));
    else if (window->KeyDown(VK_UP))
        Move(Vector(90.0f, accel));
    else if (window->KeyDown(VK_DOWN))
        Move(Vector(270.0f, accel));
    else
        // se nenhuma tecla est� pressionada comece a frear
        if (speed->Magnitude() > 0.1f)
            Move(Vector(speed->Angle() + 180.0f, 5.0f * gameTime));
        else
            // velocidade muita baixa, n�o use soma vetorial, apenas pare
            speed->ScaleTo(0.0f);
    
    // movimenta objeto pelo seu vetor velocidade
    Translate(speed->XComponent() * 50.0f * gameTime, -speed->YComponent() * 50.0f * gameTime);

    // dispara m�ssil
    if (window->KeyPress(VK_SPACE))
    {
        TelaInicial::audio->Play(FIRE);
        Fazendinha::scene->Add(new Missile(), STATIC);
    }

    // atualiza calda do jogador
    /*tail->Config().angle = speed->Angle() + 180;
    tail->Generate(x - 10 * cos(speed->Radians()), y + 10 * sin(speed->Radians()));
    tail->Update(gameTime);*/

    // restringe a �rea do jogo
    if (x < 50)
        MoveTo(50, y);
    if (y < 50)
        MoveTo(x, 50);
    if (x > game->Width() - 50)
        MoveTo(game->Width() - 50, y);
    if (y > game->Height() - 50)
        MoveTo(x, game->Height() - 50);

    // ----------------------------------------------------------------------------
    //                          COME�O DA L�GICA
    // ----------------------------------------------------------------------------

    if (usavel != nullptr) {
        if (usavel->itemType == ITEMREGADOR) {

            state = TOOL;
            if (window->KeyPress('R')) {
                Tool* regador = new Tool();
                Fazendinha::scene->Add(regador, MOVING);
                regador->MoveTo(Fazendinha::player->X(), Fazendinha::player->Y());
            }
        }

        if (usavel->itemType == ITEMARADOR) {

            state = TOOL;
            if (window->KeyPress('R')) {
                Tool* arador = new Tool(ARADOR);
                Fazendinha::scene->Add(arador, MOVING);
                arador->MoveTo(Fazendinha::player->X(), Fazendinha::player->Y());
            }
        }
    }

}

// ---------------------------------------------------------------------------------

void Player::Draw()
{
    sprite->Draw(x, y, Layer::MIDDLE, 1.0f, -speed->Angle() + 90.0f);
}


// -------------------------------------------------------------------------------
