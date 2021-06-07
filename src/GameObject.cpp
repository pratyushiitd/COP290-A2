#include "../Resources/Game/GameObject.hpp"

int SCR_WIDTH = 1184;
int SCR_HEIGHT = 1184;
int til_DIM = 32;

TileGraph* Tgraph = nullptr;
GameObject::GameObject(const char* texSheet)
{
    objTexture = TextureManager::LoadTexture(texSheet); // Pacman texture

	Tgraph = new TileGraph(SCR_HEIGHT / til_DIM, SCR_WIDTH / til_DIM); // Initialize the Tile Map for Player movement

    currTile = Tgraph->GetTileAt(32, 32); // Initialize the starting tile
	nextTile = NULL;

	if (currTile != NULL) {
		// currTile->SetPacman(this);
		
		position.x = currTile->GetPosition().x * Width;
		position.y = currTile->GetPosition().y * Height;
		//Starting coordinates
	}
	else {
		position.x = 32;
		position.y = 32;
	}

	collider.w = Width;
	collider.h = Height;

	moveDir = MOVE_RIGHT;
	nextDir = MOVE_RIGHT;

    dest.w = til_DIM;
    dest.h = til_DIM;

	frame = 0;
	frameCount = 0;

    toDelete_pac = false;
	LoadMedia();
}

// void GameObject::SetTile(Tile* newTile)
// {
// 	if (currTile != NULL)
// 		currTile->SetPacman(NULL);

// 	currTile = newTile;
	
// 	if (currTile != NULL) {
// 		currTile->SetPacman(this);

// 		position.x = currTile->GetPosition().x * Tile::Width;
// 		position.y = currTile->GetPosition().y * Tile::Height;
// 	}
// }

void GameObject::SetNextTile(Tile* newNextTile)
{
	nextTile = newNextTile;
}


bool GameObject::LoadMedia()
{
	//if (!pacmanTexture->LoadFromImage("./Resources/PacMan.bmp"))
	//	return false;

	// Leftward movment animation clips
	leftAnimClips[0].x = 0;
    leftAnimClips[0].y = 0;
    leftAnimClips[0].w = 32;
    leftAnimClips[0].h = 32;

    leftAnimClips[1].x = 32;
    leftAnimClips[1].y = 0;
    leftAnimClips[1].w = 32;
    leftAnimClips[1].h = 32;

    // Right movement animation clips
    rightAnimClips[0].x = 0;
    rightAnimClips[0].y = 32;
    rightAnimClips[0].w = 32;
    rightAnimClips[0].h = 32;

    rightAnimClips[1].x = 32;
    rightAnimClips[1].y = 32;
    rightAnimClips[1].w = 32;
    rightAnimClips[1].h = 32;

    // Downward movement animation clips
    downAnimClips[0].x = 64;
    downAnimClips[0].y = 0;
    downAnimClips[0].w = 32;
    downAnimClips[0].h = 32;

    downAnimClips[1].x = 96;
    downAnimClips[1].y = 0;
    downAnimClips[1].w = 32;
    downAnimClips[1].h = 32;

    // Upward movement animation clips
    upAnimClips[0].x = 64;
    upAnimClips[0].y = 32;
    upAnimClips[0].w = 32;
    upAnimClips[0].h = 32;

    upAnimClips[1].x = 96;
    upAnimClips[1].y = 32;
    upAnimClips[1].w = 32;
    upAnimClips[1].h = 32;

	return true;
}

void GameObject::handleEvent(SDL_Event e)
{
    //std::cout << "Player Event handling" << std::endl;

    if (e.type == SDL_KEYDOWN  && e.key.repeat == 0){
        switch (e.key.keysym.sym){
        case SDLK_UP:
            next_Dir = MOVE_UP;
            // std::cout << y_pos << std::endl;
            break;
        case SDLK_DOWN:
            next_Dir = MOVE_DOWN;
            // std::cout << y_pos << std::endl;
            break;
        case SDLK_LEFT:
            next_Dir = MOVE_LEFT;
            // std::cout << x_pos << std::endl;
            break;
        case SDLK_RIGHT:
            next_Dir = MOVE_RIGHT;
            // std::cout << x_pos << std::endl;
            break;
        default:
            break;
        }
        //validateMovement();
    }
}

bool GameObject::TryToMove(MoveDirection direction)
{
	// Get destination tile depening on the direction of movment
	// switch (direction)
	// {
	// case MOVE_UP:
	// 	destTile = Tgraph->GetTileAt(currTile->GetPosition().x, currTile->GetPosition().y - 1);
	// 	break;
	// case MOVE_DOWN:
	// 	destTile = Tgraph->GetTileAt(currTile->GetPosition().x, currTile->GetPosition().y + 1);
	// 	break;
	// case MOVE_LEFT:
	// 	destTile = Tgraph->GetTileAt(currTile->GetPosition().x - 1, currTile->GetPosition().y);
	// 	break;
	// case MOVE_RIGHT:
	// 	destTile = Tgraph->GetTileAt(currTile->GetPosition().x + 1, currTile->GetPosition().y);
	// 	break;
	// }
	switch (direction)
	{
		case MOVE_UP:
			if (Tgraph->GetTileAt(position.x, position.y - Velocity + 1)->getType() == 'w'){
					//|| Tgraph->GetTileAt(position.x + til_DIM, position.y - Velocity)->getType() == 'w'){
						return false;
						break;
					}
			else{
				position.y = position.y - Velocity;
				return true;
			}
		case MOVE_DOWN:
			if (Tgraph->GetTileAt(position.x, position.y + Velocity -1+ til_DIM)->getType() == 'w'){
					//|| Tgraph->GetTileAt(position.x + til_DIM, position.y + Velocity + til_DIM)->getType() == 'w'){
						return false;
						break;
					}
			else{
				position.y += Velocity;
				return true;
			}
		case MOVE_RIGHT:
			if (Tgraph->GetTileAt(position.x + Velocity-1 + til_DIM, position.y)->getType() == 'w'){
					//|| Tgraph->GetTileAt(position.x + Velocity + til_DIM, position.y + til_DIM)->getType() == 'w'){
						return false;
						break;
					}
			else{
				position.x += Velocity;
				return true;
			}
		case MOVE_LEFT:
			if (Tgraph->GetTileAt(position.x - Velocity+1, position.y)->getType() == 'w'){
					//|| Tgraph->GetTileAt(position.x - Velocity, position.y + til_DIM)->getType() == 'w'){
						return false;
						break;
					}
			else{
				position.x -= Velocity;
				return true;
			}

	}

	// If the tile's NULL, we can't go there
	// if (destTile == NULL) {
	// 	SetNextTile(NULL);
	// 	return false;
	// }

	// // If the tile has got a wall in it, we can't go there
	// if (destTile->getType() == 'w') {
	// 	SetNextTile(NULL);
	// 	return false;
	// }

	//SetNextTile(destTile);

	return false;
}

GameObject::~GameObject()
{
    
}


void GameObject::Destroy()
{
    SDL_DestroyTexture(objTexture);
    objTexture = NULL;
}

void GameObject::update()
{
	// Animation of pacman
	// if (moving) {
		frameCount++;
		frame = frameCount / 8;

		if (frame > MoveFrames - 1) {
			frame = 0;
			frameCount = 0;
		}
	// }
	
	// Change of tile/movement
	// if (nextTile == currTile || nextTile == NULL) {
	// 	if (nextDir != moveDir && TryToMove(nextDir))
	// 		moveDir = nextDir;
	// 	else
	// 		TryToMove(moveDir);

	// 	if (nextTile == NULL)
	// 		moving = false;
// 	else	
	// 		moving = true;
	// }
	// else {
	// 	switch (moveDir)
	// 	{
	// 	case MOVE_UP:
	// 		position.y = std::max(position.y - Velocity, nextTile->GetPosition().y * Tile::Height);
	// 		break;
	// 	case MOVE_DOWN:
	// 		position.y = std::min(position.y + Velocity, nextTile->GetPosition().y * Tile::Height);
	// 		break;
	// 	case MOVE_LEFT:
	// 		position.x = std::max(position.x - Velocity, nextTile->GetPosition().x * Tile::Width);
	// 		break;
	// 	case MOVE_RIGHT:
	// 		position.x = std::min(position.x + Velocity, nextTile->GetPosition().x * Tile::Width);
	// 		break;
	// 	}

	// 	collider.x = position.x;
	// 	collider.y = position.y;

	// 	if ((moveDir == MOVE_DOWN || moveDir == MOVE_UP) && position.y == nextTile->GetPosition().y * Tile::Height)
	// 		SetTile(nextTile);

	// 	if ((moveDir == MOVE_LEFT || moveDir == MOVE_RIGHT) && position.x == nextTile->GetPosition().x * Tile::Width)
	// 		SetTile(nextTile);
	// }
	if (position.x%til_DIM || position.y%til_DIM) TryToMove(curr_Dir);
	else if (!TryToMove(next_Dir)){
		TryToMove(curr_Dir);
	}
	else{
		curr_Dir = next_Dir;
	}
}

void GameObject::render()
{
	SDL_Rect* animClip = NULL;

	switch (curr_Dir)
	{
	case MOVE_UP:
		animClip = &upAnimClips[frame];
		break;
	case MOVE_DOWN:
		animClip = &downAnimClips[frame];
		break;
	case MOVE_LEFT:
		animClip = &leftAnimClips[frame];
		break;
	case MOVE_RIGHT:
		animClip = &rightAnimClips[frame];
		break;
	}
    dest.x = position.x;
    dest.y = position.y;
	std::cout << position.x << " " << position.y << std::endl;
    SDL_RenderCopy(Game::gameRenderer, objTexture, animClip, &dest);
	//pacmanTexture->Render(position.x, position.y, animClip);
}

void GameObject::Delete()
{
	// Calling the base function
	toDelete_pac = true;

	//currTile->SetPacman(NULL);
}

MoveDirection GameObject::GetMoveDirection()
{
	return moveDir;
}

SDL_Rect GameObject::GetCollider()
{
	return collider;
}

// SDL_Point GameObject::GetPosition()
// {
// 	return position;
// }

// Tile* GameObject::GetTile()
// {
// 	return currTile;
// }

// Tile* GameObject::GetNextTile()
// {
// 	return nextTile;
// }

bool GameObject::IsMoving()
{
	return moving;
}