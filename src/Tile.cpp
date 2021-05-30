#include "../Resources/Game/Tile.hpp"

Tile::Tile(){
    position = {0,0};
}

Tile::Tile(int x, int y){
    position = {x,y};
}

SDL_Point Tile::GetPosition(){
    return position;
}
