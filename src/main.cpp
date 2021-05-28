#include "../Resources/Game/Game.hpp"

Game *game = nullptr;
int SCREEN_WIDTH = 940;
int SCREEN_HEIGHT = 940;
const char *background = "../Resources/LOR.jpg";
SDL_Rect *rect = NULL;
const int FPS = 30;
const int frameDelay = 1000 / FPS;
Uint32 frameStart = 0;
int frameTime;
const int TILE_DIM = 32;
const int xsize = 37;
const int ysize = 37;
SDL_Texture *get_map_texture(SDL_Renderer *renderer);

int main(int argc, char *argv[]){

    game = new Game();
    game->init("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    freopen("../outputs/matrix.out", "r", stdin);
        int array_2d[xsize][ysize];
        for (int i = 0; i < xsize; i++)
        {
            for (int j = 0; j < ysize; j++)
            {
                std::cin >> array_2d[i][j];
            }
        }
    
    SDL_Surface *surface_back = IMG_Load(background);
    SDL_Texture *background_Tex = SDL_CreateTextureFromSurface(game->gameRenderer, surface_back);
    SDL_Texture *map_texture = get_map_texture(game->gameRenderer, array_2d);

    while(game->isRunning()){
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->render_from_Texture(background_Tex);
        game->render_from_Texture(map_texture);
        game->update();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }
    SDL_FreeSurface(surface_back);
    surface_back = NULL;
    SDL_DestroyTexture( background_Tex );
    background_Tex = NULL;

    SDL_DestroyTexture( map_texture );
    map_texture = NULL;
    game->clear();
    return 0;
}
SDL_Texture *get_map_texture(SDL_Renderer *renderer, int array_2d[][])
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
    SDL_SetRenderTarget(renderer, map_texture);
    int i, j;
    for (i = 0; i < SCREEN_HEIGHT / TILE_DIM; i++)
    {
        for (j = 0; j < SCREEN_WIDTH / TILE_DIM; j++)
        {
            if (!array_2d[i][j])
            {
                rect.x = TILE_DIM * j;
                rect.y = TILE_DIM * i;
                SDL_RenderCopy(renderer, tex, NULL, &rect);
            }
        }
    }
    SDL_SetRenderTarget(renderer, NULL);
    return map_texture;
}