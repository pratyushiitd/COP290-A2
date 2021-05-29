
#include "../Resources/Game/TextureManager.hpp"
#include "../Resources/Game/Map.hpp"

const char *background_file = "../Resources/LOR.jpg";
const char *tile_file = "../Resources/tile.bmp";
const char *mazeFile = "../outputs/matrix.out";
const int TILE_DIM = 32;

void Map::LoadMaze(){
    freopen(mazeFile, "r", stdin);
    for (int i = 0; i < x_size; i++)
    {
        for (int j = 0; j < y_size; j++)
        {
            std::cin >> array_2d[i][j];
        }
    }
}
Map::Map(){
    src.x = src.h = src.w = src.y = 0;
    dest.x = dest.y = 0;
    dest.h = dest.w = TILE_DIM;
    backGround = TextureManager::LoadTexture(background_file, false);
    TileTexture = TextureManager::LoadTexture(tile_file, true);

}

void Map::DrawMap(SDL_Renderer* ren){
    SDL_RenderCopy(ren, backGround, NULL, NULL);
    for (unsigned int i = 0; i < y_size; i++) {

        for (unsigned int j = 0; j < x_size; j++) {
            dest.x = TILE_DIM * j;
            dest.y = TILE_DIM * i;
            if (!array_2d[i][j]){
                SDL_RenderCopy(ren, TileTexture, NULL, &dest);
            }
        }
    }
}
Map::~Map(){}

