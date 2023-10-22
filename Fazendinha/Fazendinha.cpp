/**********************************************************************************
// Fazendinha (Código Fonte)
// 
// Criação:     23 Out 2012
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2022
//
// Descrição:   Demonstração da versão final do motor
//
**********************************************************************************/

#include "Resources.h"
#include "Fazendinha.h"
#include "Engine.h"    
#include "Magenta.h"
#include "Blue.h"    
#include "Green.h"
#include "Orange.h"
#include "Delay.h"
#include "WorldBuilder.h"
#include "Filter.h"
#include "Plantation.h"
#include "Ground.h"
// ------------------------------------------------------------------------------

Player * Fazendinha::player  = nullptr;
Audio  * Fazendinha::audio   = nullptr;
Scene  * Fazendinha::scene   = nullptr;
bool     Fazendinha::viewHUD = false;
Timer Fazendinha::timer;
uint Fazendinha::dayState = DAY;
int Fazendinha::dayCount = 1;

// ------------------------------------------------------------------------------

void Fazendinha::Init() 
{
    // cria sistema de áudio
    audio = new Audio();
    audio->Add(THEME, "Resources/Theme.wav");
    audio->Add(FIRE, "Resources/Fire.wav");
    audio->Add(HITWALL, "Resources/Hitwall.wav");
    audio->Add(EXPLODE, "Resources/Explode.wav");
    audio->Add(START, "Resources/Start.wav");

    // ajusta volumes
    audio->Volume(FIRE, 0.2f);
    audio->Volume(START, 0.8f);

    // carrega/incializa objetos
    backg   = new Background("Resources/Space.jpg");
    player  = new Player();
    scene   = new Scene();

    // cria o painel de informações
    hud = new Hud();
    WorldBuilder * builder = new WorldBuilder("Resources/map.png");
    // adiciona objetos na cena (sem colisão)
    scene->Add(player, STATIC);

    // ----------------------
    // inicializa a viewport
    // ----------------------

    // calcula posição para manter viewport centralizada
    float difx = (game->Width() - window->Width()) / 2.0f;
    float dify = (game->Height() - window->Height()) / 2.0f;

    // inicializa viewport para o centro do mundo
    viewport.left = 0.0f + difx;
    viewport.right = viewport.left + window->Width();
    viewport.top = 0.0f + dify;
    viewport.bottom = viewport.top + window->Height();


    // Carregamento das coisas do jogo em si

    // Aqui já começa a configuração do jogo em si
    timer.Start();

    Filter* filter = new Filter();
    scene->Add(filter, STATIC);

    Plantation* plant = new Plantation(0);
    scene->Add(plant, STATIC);

}

// ------------------------------------------------------------------------------

void Fazendinha::Update()
{
    // sai com o pressionamento da tecla ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza cena e calcula colisões
    scene->Update();
    scene->CollisionDetection();

    // ativa ou desativa a bounding box
    if (window->KeyPress('B')) {
        viewBBox = !viewBBox;
        Filter::activated = !Filter::activated;
    }
       
    // ativa ou desativa o heads up display
    if (window->KeyPress('H'))
        viewHUD = !viewHUD;

    // --------------------
    // atualiza a viewport
    // --------------------

    viewport.left   = player->X() - window->CenterX();
    viewport.right  = player->X() + window->CenterX();
    viewport.top    = player->Y() - window->CenterY();
    viewport.bottom = player->Y() + window->CenterY();
            
    if (viewport.left < 0)
    {
        viewport.left  = 0;
        viewport.right = window->Width();
    }
    else if (viewport.right > game->Width())
    {  
        viewport.left  = game->Width() - window->Width();
        viewport.right = game->Width();
    }
                  
    if (viewport.top < 0)
    {
        viewport.top  = 0;
        viewport.bottom = window->Height();
    }
    else if (viewport.bottom > game->Height())
    {
        viewport.top = game->Height() - window->Height();
        viewport.bottom = game->Height();
    }

    // ------------------------------------------------------------------------------
    //                          MECÂNICAS DE JOGO
    // ------------------------------------------------------------------------------

    if (dayState == DAY && timer.Elapsed(300.0f)) {
        Filter::activated = true;
        dayState = NIGHT;
    }
    else if (dayState == NIGHT && timer.Elapsed(600.0f)) {
        Filter::activated = false;
        dayState = DAY;
        timer.Reset();
    }

    if (window->KeyPress(VK_LBUTTON)) {
        Ground* ground = new Ground(window->MouseX() + game->viewport.left, window->MouseY() + game->viewport.top);
        scene->Add(ground, STATIC);
    }
} 

// ------------------------------------------------------------------------------

void Fazendinha::Draw()
{
    // desenha pano de fundo
    backg->Draw(viewport);

    // desenha a cena
    scene->Draw();

    // desenha painel de informações
    if (viewHUD)
        hud->Draw();

    // desenha bounding box
    if (viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Fazendinha::Finalize()
{
    delete audio;
    delete hud;
    delete scene;
    delete backg;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                     _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    // cria motor do jogo
    Engine * engine = new Engine();

    // configura motor
    engine->window->Mode(WINDOWED);
    engine->window->Size(968, 680);
    engine->window->Color(200, 24, 240);
    //engine->window->Mode(BORDERLESS);
    engine->window->Title("Fazendinha");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    engine->window->HideCursor(false);
    //engine->graphics->VSync(true);

    // cria o jogo
    Game * game = new Fazendinha();

    // configura o jogo
    game->Size(4840, 3160);
    
    // inicia execução
    engine->Start(game);

    // destrói motor e encerra jogo
    delete engine;
    return 0;
}

// ----------------------------------------------------------------------------