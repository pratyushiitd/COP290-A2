#pragma once
#include "TextureManager.hpp"

const int x_size = 37;
const int y_size = 37;
class Map
{
private:

    SDL_Rect src, dest;
    SDL_Texture* backGround;
    SDL_Texture* TileTexture;

    int array_2d[x_size][y_size];
public:
    Map(/* args */);
    ~Map();
    void LoadMaze();
    void DrawMap(SDL_Renderer* ren);
};

