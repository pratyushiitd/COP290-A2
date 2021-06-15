#pragma once
#include "Game.hpp"
#include "Constants.hpp"
class TextureManager {
    public: 
    static SDL_Texture* LoadTexture(const char * file);
};