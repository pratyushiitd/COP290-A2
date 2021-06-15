#pragma once
#include "TextureManager.hpp"
#include "Constants.hpp"

const int x_size = X_SIZE;
const int y_size = Y_SIZE;
class Map
{
private:

    SDL_Rect src, dest;
    SDL_Texture* backGround;
    SDL_Texture* TileTexture;
    SDL_Rect Button;
    //int array_2d[y_size][x_size];
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

