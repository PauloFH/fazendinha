/**********************************************************************************
// Game (C�digo Fonte)
//
// Cria��o:     08 Dez 2012
// Atualiza��o: 10 Ago 2021
// Compilador:  Visual C++ 2022
//
// Descri��o:   Uma class abstrata para representar um jogo.
//
//              Para criar um jogo o programador deve criar uma classe derivada
//              de Game e sobrescrever os m�todos Init, Update, Draw e Finalize.
//              Para rodar o jogo, deve-se passar o objeto Game para o m�todo
//              Start() de um objeto Engine.
//
**********************************************************************************/

#include "Game.h"
#include "Engine.h"

// -------------------------------------------------------------------------------
// Inicializa��o de membros est�ticos da classe

Canvas    Game::world    = { 0, 0, 0, 0 };       // �rea do jogo
Window* & Game::window   = Engine::window;       // ponteiro para a janela
Game*   & Game::game     = Engine::game;         // ponteiro para o jogo
float   & Game::gameTime = Engine::frameTime;    // tempo do �ltimo quadro

// -------------------------------------------------------------------------------

Game::Game()
{
    // o tamanho do jogo � o tamanho da janela
    Size(window->Width(), window->Height());

    // a �rea vis�vel � a mesma da janela
    viewport = { 0, 0, window->Width(), window->Height() };
}

// -------------------------------------------------------------------------------

Game::~Game()
{
}

// -------------------------------------------------------------------------------

void Game::OnPause()
{
    Sleep(10);
}

// -------------------------------------------------------------------------------

void Game::Size(float width, float height)
{
    world.width = width;
    world.height = height;
    world.centerX = width / 2;
    world.centerY = height / 2;
}

// -------------------------------------------------------------------------------