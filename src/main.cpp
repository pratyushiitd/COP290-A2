#include "../Resources/Game/Game.hpp"

Game *game = nullptr;
int SCREEN_WIDTH = 1184;
int SCREEN_HEIGHT = 1184;
const char *background = "../Resources/LOR.jpg";
SDL_Rect *rect = NULL;
const int FPS = 30;
const int frameDelay = 1000 / FPS;
Uint32 frameStart = 0;
int frameTime;
const int TILE_DIM = 32;
const int xsize= 37;
const int ysize = 37;
  int array_2d[xsize][ysize];
void *get_map_texture(SDL_Renderer *renderer);

int main(int argc, char *argv[]){

    game = new Game();
    game->init("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    freopen("../outputs/matrix.out", "r", stdin);
        for (int i = 0; i < xsize; i++)
        {
            for (int j = 0; j < ysize; j++)
            {
                std::cin >> array_2d[i][j];
            }
        }
    
    SDL_Surface *surface_back = IMG_Load(background);
    SDL_Texture *background_Tex = SDL_CreateTextureFromSurface(game->gameRenderer, surface_back);
    //SDL_Texture *map_texture = get_map_texture(game->gameRenderer);
    
    game->render_from_Texture(background_Tex);
    get_map_texture(game->gameRenderer);
    //game->render_from_Texture(map_texture);
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
    //SDL_Delay(2000);
    SDL_FreeSurface(surface_back);
    surface_back = NULL;
    SDL_DestroyTexture( background_Tex );
    background_Tex = NULL;
    // SDL_DestroyTexture( map_texture );
    // map_texture = NULL;
    game->clear();
    return 0;
}
void *get_map_texture(SDL_Renderer *renderer)
{
    SDL_Surface *bitmap = NULL;
    SDL_Texture *map_texture;
    SDL_Rect rect;
    rect.w = TILE_DIM;
    rect.h = TILE_DIM;
    bitmap = SDL_LoadBMP("../Resources/tile.bmp");
    SDL_Texture *tex = NULL;
    tex = SDL_CreateTextureFromSurface(renderer, bitmap);
    map_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
    //SDL_SetRenderTarget(renderer, map_texture);
    for (unsigned int i = 0; i < ysize; i++) {

        for (unsigned int j = 0; j < xsize; j++) {
            rect.x = TILE_DIM * j;
            rect.y = TILE_DIM * i;
            if (!array_2d[i][j]){
                SDL_RenderCopy(renderer, tex, NULL, &rect);
            }
        }
    }
    //SDL_SetRenderTarget(renderer, NULL);
    //return map_texture;
}