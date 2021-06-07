#pragma once
#include <SDL2/SDL.h>
#include "TextureManager.hpp"

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
    static const int Width = 32;
    static const int Height = 32;
	Tile(int x, int y);
    SDL_Point GetPosition();
    void SetPos(int x, int y);
    void SetType(char c);
    char getType();
};