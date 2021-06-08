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

	curr_Dir = MOVE_RIGHT;
	nextDir = MOVE_RIGHT;

    dest.w = til_DIM;
    dest.h = til_DIM;

	frame = 0;
	frameCount = 0;

    toDelete_pac = false;
	LoadMedia();
}


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

	int next_posx;
	int next_posy;
	switch (direction)
	{
		case MOVE_UP:
			next_posx = position.x;
			next_posy = position.y - Velocity + 1;
			Tgraph->remove_food(next_posx, next_posy);
			if (Tgraph->GetTileAt(next_posx, next_posy)->getType() == 'w'){
					//|| Tgraph->GetTileAt(position.x + til_DIM, position.y - Velocity)->getType() == 'w'){
						return false;
						break;
					}
			else{
				position.y = position.y - Velocity;
				return true;
			}
		case MOVE_DOWN:
			next_posx = position.x;
			next_posy = position.y + Velocity -1+ til_DIM;
			Tgraph->remove_food(next_posx, next_posy);
			if (Tgraph->GetTileAt(next_posx, next_posy)->getType() == 'w'){
					//|| Tgraph->GetTileAt(position.x + til_DIM, position.y + Velocity + til_DIM)->getType() == 'w'){
						return false;
						break;
					}
			else{
				position.y += Velocity;
				return true;
			}
		case MOVE_RIGHT:
			next_posx = position.x + Velocity-1 + til_DIM;
			next_posy = position.y;
			Tgraph->remove_food(next_posx, next_posy);
			if (Tgraph->GetTileAt(next_posx, next_posy)->getType() == 'w'){
					//|| Tgraph->GetTileAt(position.x + Velocity + til_DIM, position.y + til_DIM)->getType() == 'w'){
						return false;
						break;
					}
			else{
				position.x += Velocity;
				return true;
			}
		case MOVE_LEFT:
			next_posx = position.x - Velocity+1;
			next_posy = position.y;
			Tgraph->remove_food(next_posx, next_posy);
			if (Tgraph->GetTileAt(next_posx, next_posy)->getType() == 'w'){
					//|| Tgraph->GetTileAt(position.x - Velocity, position.y + til_DIM)->getType() == 'w'){
						return false;
						break;
					}
			else{
				position.x -= Velocity;
				return true;
			}

	}

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
	Tgraph->render_food();
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


bool GameObject::IsMoving()
{
	return moving;
}