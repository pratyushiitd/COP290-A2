#include "../Resources/Game/Tile.hpp"

Tile::Tile(){
    this->position.x = 0;
    this->position.y = 0;
}

Tile::Tile(int x, int y){
    this->position.x = x;
    this->position.y = y;
}

SDL_Point Tile::GetPosition(){  
    return position;
}
void Tile::SetPos(int x, int y)
{
	position.x = x;
	position.y = y;
}
void Tile::SetType(char c)
{
    this->Type = c;
}
char Tile::getType()
{
    return Type;
}
