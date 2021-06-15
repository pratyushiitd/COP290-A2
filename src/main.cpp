#include "../Resources/Game/Map.hpp"
#include "../Resources/Game/Game.hpp"
#include "../Resources/Game/GameObject.hpp"
#include "../Resources/Game/TileGraph.hpp"
#include "../Resources/Game/Tile.hpp"


Game *game = nullptr;
Map *map = nullptr;
const int FPS = 30;
const int frameDelay = 1000 / FPS;
Uint32 frameStart = 0;
int frameTime;

int main(int argc, char *argv[]){
    game = new Game();
    game->init("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);
    std::cout << "Game Initialization Successfull..." << std::endl;
    //std::cout << Y_SIZE << " " << X_SIZE << std::endl;
    map = new Map();
    SDL_Event e;
    bool choose = false;
    while(!choose){
        map->display(game->gameRenderer);
        while(SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT) {game->clear();game->running = false;choose = true; break;}
            choose = map->HandleTheme(e);
        }
        
    }
    map->LoadMaze();
    std::cout << "Maze Loading Successfull..." << std::endl;
    while(game->isRunning()){

        //frameStart = SDL_GetTicks();
        
        // game->update();
        // Fill the screen with black
		SDL_SetRenderDrawColor(game->gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(game->gameRenderer);
        map->DrawMap(game->gameRenderer);
		// Render all the objects
        game->handleEvents();
        game->update();
        game->render();
		//game->render();
		//Update the surface
		SDL_RenderPresent(game->gameRenderer);
    }
    //SDL_Delay(2000);
    game->clear();

    return 0;
}
