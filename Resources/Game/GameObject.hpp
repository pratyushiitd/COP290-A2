#pragma once
#include "Game.hpp"

class GameObject
{
private:
    int x_pos;
    int y_pos;
    SDL_Texture* objTexture;
    SDL_Rect src, dest;
    int curr_Dir = -1;
public:
    GameObject(const char* texture_sheet);
    ~GameObject();
    void update();
    void render();
    void handleEvent(SDL_Event e);
    void Destroy();
};

