#include "../Resources/Game/GameObject.hpp"
#include "../Resources/Game/TextureManager.hpp"

#define SPEED 4

enum {
    DIRECTION_UP,
    DIRECTION_DOWN,
    DIRECTION_LEFT,
    DIRECTION_RIGHT
};
GameObject::GameObject(const char* texSheet)
{
    objTexture = TextureManager::LoadTexture(texSheet, false);
    dest.w = 32;
    dest.h = 32;
    dest.x = 0;
    dest.y = 0;
    x_pos = 0;
    y_pos = 0;
}

void GameObject::update()
{

    //if (check_wall())
}

void GameObject::handleEvent(SDL_Event e)
{
    //std::cout << "Player Event handling" << std::endl;

    if (e.type == SDL_KEYDOWN){
        switch (e.key.keysym.sym){
        case SDLK_UP:
            y_pos-=SPEED;
            std::cout << y_pos << std::endl;
            break;
        case SDLK_DOWN:
            y_pos+=SPEED;
            std::cout << y_pos << std::endl;
            break;
        case SDLK_LEFT:
            x_pos-=SPEED;
            std::cout << x_pos << std::endl;
            break;
        case SDLK_RIGHT:
            x_pos+=SPEED;
            std::cout << x_pos << std::endl;
            break;
        default:
            break;
        }
    }
}

GameObject::~GameObject()
{

}

void GameObject::render()
{
    SDL_RenderCopy(Game::gameRenderer, objTexture, NULL, &dest);
}

void GameObject::Destroy()
{
    SDL_DestroyTexture(objTexture);
    objTexture = NULL;
}