#pragma once
#include <SDL2/SDL.h>
#include "TextureManager.hpp"
#include "Constants.hpp"
class Tile
{
private:
    SDL_Point position;
    char Type;
    /*
    w -> Wall
    r -> FreePath
    */
public:
	Tile();
    static const int Width = TILE_SIZE;
    static const int Height = TILE_SIZE;
	Tile(int x, int y);
    SDL_Point GetPosition();
    void SetPos(int x, int y);
    void SetType(char c);
    char getType();
};