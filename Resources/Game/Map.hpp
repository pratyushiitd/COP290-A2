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
    SDL_Rect Button;
    int array_2d[x_size][y_size];
    int curr_press;
    int total_themes;
public:
    Map(/* args */);
    ~Map();
    void LoadMaze();
    void DrawMap(SDL_Renderer* ren);
    bool HandleTheme(SDL_Event e);
    void display(SDL_Renderer* ren);
};

