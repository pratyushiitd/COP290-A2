#include "../Resources/Game/Game.hpp"

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
    SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    // imgFlags = IMG_INIT_JPG;
    // if( !( IMG_Init( imgFlags ) & imgFlags ) )
    // {
    //     printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
    //     return ;
    // }
    return;
}

void Game::handleEvents(){
    SDL_Event e;
    if (SDL_PollEvent( &e )){
        switch (e.type)
        {
        case SDL_QUIT:
            running = false;
            break;
        
        default:
            break;
        }
    }
    return;
}

void Game::render_from_Texture(SDL_Texture *texture){
    SDL_RenderClear(gameRenderer);
    SDL_RenderCopy(gameRenderer, texture, NULL, NULL);
    SDL_RenderPresent(gameRenderer);
}
void Game::clear(){
    // SDL_DestroyTexture( texture );
    // texture = NULL;

    SDL_DestroyTexture( TileText );
    TileText = NULL;

    //Destroy window    
    SDL_DestroyWindow( gameWindow );
    gameWindow = NULL;
    SDL_DestroyRenderer( gameRenderer );
    gameRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
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
    std::cout << count++ << std::endl;
}



