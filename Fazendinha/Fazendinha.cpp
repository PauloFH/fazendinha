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
#include "WorldBuilder.h"
#include "Filter.h"
#include "Plantation.h"
#include "Ground.h"
#include "Build.h"
#include "Animal.h"
#include "Item.h"
#include "Bau.h"
#include "Enemy.h"
#include <sstream>
// ------------------------------------------------------------------------------

Player * Fazendinha::player  = nullptr;
Audio  * Fazendinha::audio   = nullptr;
Scene  * Fazendinha::scene   = nullptr;
bool     Fazendinha::viewHUD = false;
Timer Fazendinha::timer;
uint Fazendinha::dayState = DAY;
int Fazendinha::dayCount = 1;
Mouse * Fazendinha::mouse = nullptr;
Font* Fazendinha::text = nullptr;
Inventary* Fazendinha::inventary = nullptr;
Controller* Fazendinha::gamepad = nullptr;
bool     Fazendinha::controllerOn = false;
bool Fazendinha::xboxOn = false;
// ------------------------------------------------------------------------------

void Fazendinha::Init()
{
    gamepad = new Controller();

    // tenta inicializar um controle do xbox
    xboxOn = gamepad->XboxInitialize(xboxPlayer);
    if (!xboxOn)
        controllerOn = gamepad->Initialize();

    // cria sistema de áudio
    audio = new Audio();
    audio->Add(THEME, "Resources/Thame.wav");
    audio->Add(COW_AUDIO, "Resources/cow.wav");
    audio->Add(GALINHA, "Resources/galinha.wav");
    audio->Add(CAVAR_AUDIO, "Resources/cavar.wav");
    audio->Add(AGUA_AUDIO, "Resources/agua.wav");
    audio->Add(PLANTAR_AUDIO, "Resources/planta.wav");
    audio->Volume(THEME, 0.8f);
    audio->Volume(COW_AUDIO, 1.8f);
    audio->Volume(GALINHA, 1.8f);
    // carrega/incializa objetos
    backg   = new Background("Resources/grass.png");
    player  = new Player();
    scene   = new Scene();


    // cria o painel de informações
    WorldBuilder* builder = new WorldBuilder("Resources/map.png");
    // adiciona objetos na cena (sem colisão)
    scene->Add(player, MOVING);

    // ----------------------
    // inicializa a viewport
    // ----------------------

    // calcula posição para manter viewport centralizada
    float difx = (game->Width() - window->Width()) / 2.0f;
    float dify = (game->Height() - window->Height()) / 2.0f;

    // inicializa viewport para o centro do mundo
    viewport.left = 10.0f + difx;
    viewport.right = viewport.left + window->Width();
    viewport.top = 10.0f + dify;
    viewport.bottom = viewport.top + window->Height();


    // Carregamento das coisas do jogo em si
    scene->Add(new Build(2230, 400, HOME, new Sprite("Resources/home.png")), STATIC);
    scene->Add(new Build(1500, 300, SHOP_BUILD, new Sprite("Resources/shop_day.png")), STATIC);
    scene->Add(new Build(500, 300, COMMUNITY, new Sprite("Resources/closed.png")), STATIC);
    // Aqui já começa a configuração do jogo em si
    timer.Start();

    text = new Font("Resources/text.png");
    text->Spacing(65);

    mouse = new Mouse();
    scene->Add(mouse, MOVING);

    inventary = new Inventary();
    scene->Add(inventary, STATIC);

    Item* chirivia = new Item(0, inventary->spaces[4]);
    scene->Add(chirivia, MOVING);

    Item* chirivia2 = new Item(0, inventary->spaces[2]);
    scene->Add(chirivia2, MOVING);

    Item* seedChirivia = new Item(1, inventary->spaces[5]);
    scene->Add(seedChirivia, MOVING);
    
    Item* seedChirivia2 = new Item(1, inventary->spaces[6]);
    scene->Add(seedChirivia2, MOVING);

    Filter* filter = new Filter();
    scene->Add(filter, STATIC);

    Plantation* plant = new Plantation(0);
    scene->Add(plant, STATIC);
    
    Animal* anim = new Animal(CHICKEN);
    scene->Add(anim, MOVING);

    Animal* anim2 = new Animal(COW);
    scene->Add(anim2, MOVING);
    anim2->MoveTo(anim2->X(), anim->Y() + 100);

    Bau* bau = new Bau();
    scene->Add(bau, STATIC);

    Item* regador = new Item(ITEMREGADOR, bau->bauOpened->spaces[2]);
    scene->Add(regador, MOVING);

    Item* arador = new Item(ITEMARADOR, bau->bauOpened->spaces[7]);
    scene->Add(arador, MOVING);

    Enemy* bug = new Enemy();
    scene->Add(bug, MOVING);
    audio->Play(THEME, true);
}

// ------------------------------------------------------------------------------

void Fazendinha::Update()
{
    if (controllerOn)
    {
        // seleciona próximo controle (Page Down)
        if (window->KeyPress(VK_NEXT))
            gamepad->DeviceNext();

        // seleciona controle anterior (Page Up)
        if (window->KeyPress(VK_PRIOR))
            gamepad->DevicePrev();

        gamepad->UpdateState();
    }
    else if (xboxOn)
    {
        // seleciona próximo controle (Page Down)
        if (window->KeyPress(VK_NEXT))
        {
            uint nextPlayer = (xboxPlayer + 1) % 4;

            // se controle para próximo jogador está conectado                
            if (gamepad->XboxUpdateState(nextPlayer))
                xboxPlayer = nextPlayer;
        }
        // seleciona controle anterior (Page Up)
        if (window->KeyPress(VK_PRIOR))
        {
            uint prevPlayer = xboxPlayer == 0 ? 3 : xboxPlayer - 1;

            // se controle para jogador anterior está conectado    
            if (gamepad->XboxUpdateState(prevPlayer))
                xboxPlayer = prevPlayer;
        }

        // atualiza estado do controle
        gamepad->XboxUpdateState(xboxPlayer);
    }

    if (tempo != 0) {
        tempo--;
    }
    if (tempo == 0) {
        audio->Play(COW_AUDIO);
        tempo = 800;
    }
    if ((tempo - 50) == 0){
        audio->Play(GALINHA);

    }
    // sai com o pressionamento da tecla ESC
    if (window->KeyDown(
        _ESCAPE))
        window->Close();

    // atualiza cena e calcula colisões
    scene->Update();
    scene->CollisionDetection();
    scene->DrawBBox();

    // ativa ou desativa a bounding box
    if (window->KeyPress('B') || Fazendinha::gamepad->XboxButton(ButtonA)) {
        viewBBox = !viewBBox;
        Filter::activated = !Filter::activated;
    }

    if (Filter::activated) {
        dayState = NIGHT;
    }
    else {
        dayState = DAY;
    }
       
    // ativa ou desativa o heads up display

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
        dayCount++;
        timer.Reset();
    }

    if (window->KeyPress(VK_LBUTTON) && mouse->State() != COLISAO && player->PlayerState() == ARADOR) {
        Ground* ground = new Ground(window->MouseX() + game->viewport.left, window->MouseY() + game->viewport.top);
        scene->Add(ground, MOVING);
    }

  
    for (int i = 0; i < 12; i++) {

        Item* it = nullptr;

        if (inventary->spaces[i]->cont > 0 && inventary->spaces[i]->objItem != nullptr) {
            it = dynamic_cast<Item*>(inventary->spaces[i]->objItem);
        }

        if (it != nullptr) {

            if (!it->pego && window->KeyPress(inventary->spaces[i]->chave)) {
                if (inventary->spaces[i]->ocupado) {

                    std::stringstream text;

                    text.str("");

                    text << inventary->spaces[i]->chave << ".\n";
                    OutputDebugString(text.str().c_str());

                    it->pego = true;
                    player->usavel = it;
                    //it->MoveTo(Fazendinha::player->X(), Fazendinha::player->Y() + 100);

                }
            }

            if (it->pego && window->KeyPress(inventary->spaces[i]->chave)) {
                it->pego = false;
            }
        }
    }  

} 

// ------------------------------------------------------------------------------

void Fazendinha::Draw()
{
    backg->Draw(viewport);

    scene->DrawBBox();
    // desenha pano de fundo


    // desenha a cena
    scene->Draw();

    // desenha bounding box
       

}

// ------------------------------------------------------------------------------

void Fazendinha::Finalize()
{
    delete audio;
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
    engine->window->Title("Fazendinha");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    engine->window->HideCursor(false);
    //engine->graphics->VSync(true);

    // cria o jogo
    Game * game = new Fazendinha();

    // configura o jogo
    game->Size(2846, 2046);
    
    // inicia execução
    engine->Start(game);

    // destrói motor e encerra jogo
    delete engine;
    return 0;
}

// ----------------------------------------------------------------------------