#include "../Resources/Game/TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* file)
{

    SDL_Surface* surf;
    surf = SDL_LoadBMP(file);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::gameRenderer, surf);
    SDL_FreeSurface(surf);
    surf = NULL;
    return tex;
}