/**********************************************************************************
// Player (Código Fonte)
// 
// Criação:     10 Out 2012
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2022
//
// Descrição:   Define a classe jogador
//
**********************************************************************************/

#include "Player.h" 
#include "Missile.h"
#include "Fazendinha.h"
#include "Tool.h"
#include "Plantation.h"
#include "Build.h"

// -------------------------------------------------------------------------------

Player::Player()
{
    // configuração do objeto
    //sprite = new Sprite("Resources/Player.png");
    tileset = new TileSet("Resources/player.png", 96, 192, 6, 36);
    animation = new Animation(tileset, 0.2f, true);
    placarDinheiro = new Sprite("Resources/placarDinheiro.png");


    uint normal[1] = { 0 };
    uint playerleft[3] = { 35, 34, 33 };
    uint normalleft[1] = { 35 };
    uint playerright[3] = { 3, 4, 5 };
    uint normalright[1] = { 3 };
    uint playerup[2] = { 8, 9 };
    uint normalup[1] = { 7 };
    uint playerdown[2] = { 1, 2 };
    uint normaldown[1] = { 0 };

    animation->Add(NORMAL, normal, 1);
    animation->Add(PLAYERLEFT, playerleft, 3);
    animation->Add(PLAYERRIGHT, playerright, 3);
    animation->Add(PLAYERUP, playerup, 2);
    animation->Add(PLAYERDOWN, playerdown, 2);
    animation->Add(NORMALLEFT, normalleft, 1);
    animation->Add(NORMALRIGHT, normalright, 1);
    animation->Add(NORMALUP, normalup, 1);
    animation->Add(NORMALDOWN, normaldown, 1);

    speed  = new Vector(90.0f, 0.0f);

    vel = 250;

    //BBox(new Rect(-48, -96, 47, 95));
    BBox(new Rect(-48, -0, 47, 95));
    MoveTo(500, 600);
   // MoveTo(game->CenterX(), game->CenterY());
    type = PLAYER;

    Scale(0.4f);

}

// -------------------------------------------------------------------------------

Player::~Player()
{
    delete animation;
    delete tileset;
    delete speed;
}

// -------------------------------------------------------------------------------

void Player::Move(Vector && v)
{
    speed->Add(v);

    // limita velocidade máxima
    if (speed->Magnitude() > 10.0f)
        speed->ScaleTo(10.0f);

}

// -------------------------------------------------------------------------------

void Player::Update()
{

    animation->Select(state);
    animation->NextFrame();
    if (animation->Frame() == 0) {
        animation->NextFrame();
    }

    state = relaxState;
   // Translate(Fazendinha::gamepad->XboxAnalog(ThumbLX) / 218.46f * gameTime , Fazendinha::gamepad->XboxAnalog(ThumbLY) / 218.46f * gameTime);
    
    if (Fazendinha::gamepad->XboxAnalog(ThumbLY)<-30) {
        Translate(0, vel * gameTime);
        state = PLAYERDOWN;
        relaxState = NORMALDOWN;
    }
    else if (Fazendinha::gamepad->XboxAnalog(ThumbLY) > 30) {
        Translate(0, -vel * gameTime);
        state = PLAYERUP;
        relaxState = NORMALUP;
    }

    if (Fazendinha::gamepad->XboxAnalog(ThumbLX) > 30) {
        Translate(vel * gameTime, 0);
        state = PLAYERRIGHT;
        relaxState = NORMALRIGHT;
    }
    else if (Fazendinha::gamepad->XboxAnalog(ThumbLX) <- 30) {
        Translate(-vel * gameTime, 0);
        state = PLAYERLEFT;
        relaxState = NORMALLEFT;
    }

    if (window->KeyDown(VK_DOWN) || window->KeyDown('S')) {
        Translate(0, vel * gameTime);
        state = PLAYERDOWN;
        relaxState = NORMALDOWN;
    }
    else if (window->KeyDown(VK_UP) || window->KeyDown('W')) {
        Translate(0, -vel * gameTime);
        state = PLAYERUP;
        relaxState = NORMALUP;
    }

    if (window->KeyDown(VK_RIGHT) || window->KeyDown('D')) {
        Translate(vel * gameTime, 0);
        state = PLAYERRIGHT;
        relaxState = NORMALRIGHT;
    }
    else if (window->KeyDown(VK_LEFT) || window->KeyDown('A')) {
        Translate(-vel * gameTime, 0);
        state = PLAYERLEFT;
        relaxState = NORMALLEFT;
    }

    /*
    // magnitude do vetor aceleração
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
        // se nenhuma tecla está pressionada comece a frear
        if (speed->Magnitude() > 0.1f)
            Move(Vector(speed->Angle() + 180.0f, 5.0f * gameTime));
        else
            // velocidade muita baixa, não use soma vetorial, apenas pare
            speed->ScaleTo(0.0f);
    
    // movimenta objeto pelo seu vetor velocidade
    Translate(speed->XComponent() * 50.0f * gameTime, -speed->YComponent() * 50.0f * gameTime);
    */
    // dispara míssil
    if (window->KeyPress(VK_SPACE))
    {
    }

    // atualiza calda do jogador
    /*tail->Config().angle = speed->Angle() + 180;
    tail->Generate(x - 10 * cos(speed->Radians()), y + 10 * sin(speed->Radians()));
    tail->Update(gameTime);*/

    // restringe a área do jogo
    if (x < 50)
        MoveTo(50, y);
    if (y < 50)
        MoveTo(x, 50);
    if (x > game->Width() - 50)
        MoveTo(game->Width() - 50, y);
    if (y > game->Height() - 50)
        MoveTo(x, game->Height() - 50);

    // ----------------------------------------------------------------------------
    //                          COMEÇO DA LÓGICA
    // ----------------------------------------------------------------------------

    if (usavel != nullptr) {
        if (usavel->itemType == ITEMREGADOR) {
            
            //state = TOOL;
            if (window->KeyPress('R') || Fazendinha::gamepad->XboxButton(ButtonA)) {
                Tool* regador = new Tool();
                Fazendinha::scene->Add(regador, MOVING);
                regador->MoveTo(Fazendinha::player->X(), Fazendinha::player->Y());

                if (state == PLAYERLEFT || state == NORMALLEFT) {
                    regador->state = TOOLANOTHERSIDE;
                    regador->MoveTo(x - 16, y);
                }
                if (state == PLAYERRIGHT || state == NORMALRIGHT) {
                    regador->state = TOOLSIDE;
                    regador->MoveTo(x + 16, y);
                }
                if (state == PLAYERDOWN || state == NORMALDOWN) {
                    regador->state == TOOLFRONT;
                }
                Fazendinha::audio->Play(AGUA_AUDIO);
            }

        }

        if (usavel->itemType == ITEMARADOR) {
           
            //state = TOOL;
            if (window->KeyPress('R') || Fazendinha::gamepad->XboxButton(ButtonA)) {
                Tool* arador = new Tool(ARADOR);
                Fazendinha::scene->Add(arador, MOVING);
                arador->MoveTo(Fazendinha::player->X(), Fazendinha::player->Y());
                Fazendinha::audio->Play(CAVAR_AUDIO);
                if (state == PLAYERLEFT || state == NORMALLEFT) {
                    arador->state = TOOLANOTHERSIDE;
                }
                if (state == PLAYERRIGHT || state == NORMALRIGHT) {
                    arador->state = TOOLSIDE;
                }
                if (state == PLAYERDOWN || state == NORMALDOWN) {
                    arador->state == TOOLFRONT;
                }
            }
        }

        if (usavel->itemType == SEEDCHIRIVIA) {
            
            if (window->KeyPress('R') || Fazendinha::gamepad->XboxButton(ButtonA)) {
                Plantation* plant = new Plantation(CHIRIVIA);
                Fazendinha::scene->Add(plant, MOVING);
                usavel->space->cont--;
                plant->MoveTo(Fazendinha::mouse->X() - 8, Fazendinha::mouse->Y() - 8);
                Fazendinha::audio->Play(PLANTAR_AUDIO);
            }
        }
        if (usavel->itemType == SEEDCOUVEFLOR) {

            if (window->KeyPress('R') || Fazendinha::gamepad->XboxButton(ButtonA)) {
                Plantation* plant = new Plantation(COUVEFLOR);
                Fazendinha::scene->Add(plant, MOVING);
                usavel->space->cont--;
                plant->MoveTo(Fazendinha::mouse->X() - 8, Fazendinha::mouse->Y() - 8);

            }
        }
        if (usavel->itemType == SEEDMELAO) {

            if (window->KeyPress('R') || Fazendinha::gamepad->XboxButton(ButtonA)) {
                Plantation* plant = new Plantation(MELAO);
                Fazendinha::scene->Add(plant, MOVING);
                usavel->space->cont--;
                plant->MoveTo(Fazendinha::mouse->X() - 8, Fazendinha::mouse->Y() - 8);

            }
        }
        if (usavel->itemType == SEEDBERINJELA) {

            if (window->KeyPress('R') || Fazendinha::gamepad->XboxButton(ButtonA)) {
                Plantation* plant = new Plantation(BERINJELA);
                Fazendinha::scene->Add(plant, MOVING);
                usavel->space->cont--;
                plant->MoveTo(Fazendinha::mouse->X() - 8, Fazendinha::mouse->Y() - 8);

            }
        }
        if (usavel->itemType == SEEDABOBORA) {

            if (window->KeyPress('R') || Fazendinha::gamepad->XboxButton(ButtonA)) {
                Plantation* plant = new Plantation(ABOBORA);
                Fazendinha::scene->Add(plant, MOVING);
                usavel->space->cont--;
                plant->MoveTo(Fazendinha::mouse->X() - 8, Fazendinha::mouse->Y() - 8);

            }
        }
        if (usavel->itemType == SEEDMILHO) {

            if (window->KeyPress('R') || Fazendinha::gamepad->XboxButton(ButtonA)) {
                Plantation* plant = new Plantation(MILHO);
                Fazendinha::scene->Add(plant, MOVING);
                usavel->space->cont--;
                plant->MoveTo(Fazendinha::mouse->X() - 8, Fazendinha::mouse->Y() - 8);

            }
        }
        if (usavel->itemType == SEEDBATATA) {

            if (window->KeyPress('R') || Fazendinha::gamepad->XboxButton(ButtonA)) {
                Plantation* plant = new Plantation(BATATA);
                Fazendinha::scene->Add(plant, MOVING);
                usavel->space->cont--;
                plant->MoveTo(Fazendinha::mouse->X() - 8, Fazendinha::mouse->Y() - 8);

            }
        }
        if (usavel->itemType == SEEDABACAXI) {

            if (window->KeyPress('R') || Fazendinha::gamepad->XboxButton(ButtonA)) {
                Plantation* plant = new Plantation(ABACAXI);
                Fazendinha::scene->Add(plant, MOVING);
                usavel->space->cont--;
                plant->MoveTo(Fazendinha::mouse->X() - 8, Fazendinha::mouse->Y() - 8);

            }
        }

    }

    vel = 250;

}

// ---------------------------------------------------------------------------------

void Player::Draw()
{
    animation->Draw(x, y, Layer::MIDDLE, scale);
    Color Black(0.0f, 0.0f, 0.0f, 5.0f);
    string dindin = std::to_string(dinheiro);
    Fazendinha::text->Draw(60, 50, dindin, Black, Layer::FRONT, 0.2f);
    placarDinheiro->Draw(game->viewport.left + 100, game->viewport.top + 50, Layer::FRONT + 0.01f);
}


// -------------------------------------------------------------------------------

void Player::OnCollision(Object* obj) {
    if (obj->Type() == HOME || obj->Type() == SHOP_BUILD || obj->Type() == COMMUNITY) {

        vel = 0;

        Build* build = dynamic_cast<Build*>(obj);

        // Calcula a direção da colisão
        float collisionDirectionX = x - build->X();
        float collisionDirectionY = y - build->Y();

        // Define a distância mínima para evitar sobreposição
        float minimumDistance = 40.0f;

        // Verifica a direção da colisão e ajusta a posição do jogador
        
            // A colisão é principalmente horizontal, ajuste na direção X
            if (collisionDirectionX > 0) {
                MoveTo(x + minimumDistance, y);
            }
            else {
                MoveTo(x - minimumDistance, y);
            }
        
       
            // A colisão é principalmente vertical, ajuste na direção Y
            if (collisionDirectionY > 0) {
                MoveTo(x, y+ minimumDistance);
            }
            else {
                MoveTo(x, y- minimumDistance);
            }
        
    }
}


