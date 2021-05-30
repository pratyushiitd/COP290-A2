#include "../Resources/Game/Game.hpp"
#include "../Resources/Game/TextureManager.hpp"
#include "../Resources/Game/GameObject.hpp"

SDL_Renderer* Game::gameRenderer = nullptr;
GameObject* player = nullptr;

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool full_scr){
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("SDL couldn't get initialized! SDL Error : %s\n", SDL_GetError());
        running = false;
        return;
    }
    int flag = SDL_WINDOW_SHOWN;
    if (full_scr){
        flag = SDL_WINDOW_FULLSCREEN;
    }
    gameWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
    if (gameWindow == NULL){
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        running = false;
        return ;
    }
    gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gameRenderer == NULL){
        printf( "Renderer could not be created! SDL_Error: %s\n", SDL_GetError() );
        running = false;
        return ;
    }
    SDL_RenderClear(gameRenderer);
    SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    player = new GameObject("../Resources/player.jpg");
    return;
}

void Game::handleEvents(){
    SDL_Event e;
    while (SDL_PollEvent( &e )){
        switch (e.type)
        {
        case SDL_QUIT:
            std::cout << "Requesting to Quit.." << std::endl;
            running = false;
            break;
        
        default:
            break;
        }
        player->handleEvent(e);
    }
    return;
}

void Game::render(){
    player->render();
    //SDL_RenderPresent(Game::gameRenderer);
    //SDL_RenderPresent(gameRenderer);
}
void Game::clear(){
    // SDL_DestroyTexture( texture );
    // texture = NULL;
    //Destroy window    
    SDL_DestroyWindow( gameWindow );
    gameWindow = NULL;
    SDL_DestroyRenderer( gameRenderer );
    gameRenderer = NULL;
    player->Destroy();
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
    std::cout << "Game Exit Success!" << std::endl;
}
Game::Game(){
    //
    running = true;
    count = 0;
}

Game::~Game(){
    //
}

bool Game::isRunning(){
    return running;
}

void Game::update(){
    //
    count++;
    player->update();
}
void Game::closeRequest(){
    running = false;
}



