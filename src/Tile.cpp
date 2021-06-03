#include "../Resources/Game/Tile.hpp"

Tile::Tile(){
    this->position = {0,0};

}

Tile::Tile(int x, int y){
    this->position = {x,y};
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
