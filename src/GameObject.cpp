#include "../Resources/Game/GameObject.hpp"

#define SPEED 2
int SCR_WIDTH = 1184;
int SCR_HEIGHT = 1184;
int til_DIM = 32;

TileGraph* Tgraph;
GameObject::GameObject(const char* texSheet)
{
    objTexture = TextureManager::LoadTexture(texSheet, false);
    dest.w = 32;
    dest.h = 32;
    dest.x = 32;
    dest.y = 32;
    x_pos = 32;
    y_pos = 32;
    Tgraph = new TileGraph();
    curr_Dir = MOVE_STILL;
}

void GameObject::update()
{
    std::cout << x_pos << " " << y_pos << std::endl;
    if (curr_Dir == MOVE_STILL) return;
    if (curr_Dir == MOVE_RIGHT) x_pos+=SPEED;
    if (curr_Dir == MOVE_LEFT) x_pos-=SPEED;
    if (curr_Dir == MOVE_UP) y_pos-=SPEED;
    if (curr_Dir == MOVE_LEFT) y_pos+=SPEED;
    dest.x = x_pos;
    dest.y = y_pos;
    //if (check_wall())
}

void GameObject::handleEvent(SDL_Event e)
{
    //std::cout << "Player Event handling" << std::endl;

    if (e.type == SDL_KEYDOWN  && e.key.repeat == 0){
        switch (e.key.keysym.sym){
        case SDLK_UP:
            curr_Dir = MOVE_UP;
            // std::cout << y_pos << std::endl;
            break;
        case SDLK_DOWN:
            curr_Dir = MOVE_DOWN;
            // std::cout << y_pos << std::endl;
            break;
        case SDLK_LEFT:
            curr_Dir = MOVE_LEFT;
            // std::cout << x_pos << std::endl;
            break;
        case SDLK_RIGHT:
            curr_Dir = MOVE_RIGHT;
            // std::cout << x_pos << std::endl;
            break;
        default:
            break;
        }
        validateMovement();
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

void GameObject::validateMovement()
{
    if (curr_Dir == MOVE_UP){
        if (y_pos - SPEED < 0 || Tgraph->GetTileAt(x_pos, y_pos-SPEED)->getType() == 'w'){
            curr_Dir = MOVE_STILL;
        }else{
            y_pos -= SPEED;
        }
    }
    else if (curr_Dir == MOVE_DOWN){
        if (y_pos+til_DIM+SPEED > SCR_HEIGHT || Tgraph->GetTileAt(x_pos, y_pos+SPEED+til_DIM)->getType() == 'w'){
            curr_Dir = MOVE_STILL;
        }else{
            y_pos += SPEED;
        }
    }
    else if (curr_Dir == MOVE_LEFT){
        if ( x_pos - SPEED < 0 || Tgraph->GetTileAt(x_pos-SPEED, y_pos)->getType() == 'w'){
            curr_Dir = MOVE_STILL;
        }else{
            x_pos -= SPEED;
        }
    }
    else if (curr_Dir == MOVE_RIGHT){
        if (x_pos + SPEED + til_DIM > SCR_WIDTH || Tgraph->GetTileAt(x_pos + SPEED + til_DIM, y_pos)->getType() == 'w'){
            curr_Dir = MOVE_STILL;
        }else{
            x_pos += SPEED;
        }
    }
}