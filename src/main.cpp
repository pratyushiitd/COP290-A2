#include "../Resources/Game/TextureManager.hpp"
#include "../Resources/Game/Map.hpp"

Game *game = nullptr;
Map *map = nullptr;
int SCREEN_WIDTH = 1184;
int SCREEN_HEIGHT = 1184;

const int FPS = 30;
const int frameDelay = 1000 / FPS;
Uint32 frameStart = 0;
int frameTime;

int main(int argc, char *argv[]){

    game = new Game();
    game->init("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);
    std::cout << "Game Initialization Successfull..." << std::endl;
    map = new Map();
    map->LoadMaze();
    std::cout << "Maze Loading Successfull..." << std::endl;
    map->DrawMap(game->gameRenderer);
    SDL_RenderPresent(game->gameRenderer);
    while(game->isRunning()){

        //frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();

        // frameTime = SDL_GetTicks() - frameStart;
        // if (frameDelay > frameTime){
        //     SDL_Delay(frameDelay - frameTime);
        // }
    }
    game->clear();
    return 0;
}
