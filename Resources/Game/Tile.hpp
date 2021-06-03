#pragma once
#include <SDL2/SDL.h>

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
	Tile(int x, int y);
    SDL_Point GetPosition();
    void SetPos(int x, int y);
    void SetType(char c);
    char getType();
};