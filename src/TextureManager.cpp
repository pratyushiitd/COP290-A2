#include "../Resources/Game/TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* file, bool isBMP)
{

    SDL_Surface* surf;
    if (isBMP){
        surf = SDL_LoadBMP(file);
    }else{
        surf = IMG_Load(file);
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::gameRenderer, surf);
    SDL_FreeSurface(surf);
    surf = NULL;
    return tex;
}