#pragma once
#include <SDL2/SDL.h>

class Tile
{
private:
    SDL_Point position;
    
public:
    const static int Width = 32;
	const static int Height = 32;

	Tile();
	Tile(int x, int y);
    SDL_Point GetPosition();
};