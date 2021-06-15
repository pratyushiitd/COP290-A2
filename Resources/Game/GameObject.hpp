#pragma once
#include "Movedirection.hpp"
#include "TileGraph.hpp"
#include <vector>
#include "Constants.hpp"
class GameObject
{
private:
    int x_pos;
    int y_pos;
    SDL_Texture* objTexture;
    SDL_Rect src, dest;
    MoveDirection curr_Dir = MOVE_STILL;
    MoveDirection next_Dir = MOVE_STILL;
	int Width = TILE_SIZE;
	int Height = TILE_SIZE;
	int MoveFrames = MOVE_FRAMES;
    int Velocity = VELOCITY;

	// Trys to move the pacman in desired direction
	// Returns true if successful, false otherwise
	bool TryToMove(MoveDirection direction);

	// Check if pacman is colliding with other collider
	bool CheckForCollision(const SDL_Rect &otherCollider);

	// Check if given collider is colliding with another collider
	bool CheckForCollision(const SDL_Rect &collider, const SDL_Rect &otherCollider);

	SDL_Rect upAnimClips[2];
	SDL_Rect downAnimClips[2];
	SDL_Rect leftAnimClips[2];
	SDL_Rect rightAnimClips[2];

	int frame, frameCount;

	MoveDirection moveDir;
	MoveDirection nextDir;
	bool moving;
	SDL_Point position;

	Tile* currTile;
	Tile* nextTile;

	SDL_Rect collider;

	bool toDelete_pac;

public:
    GameObject(const char* texture_sheet);
    ~GameObject();
    TileGraph* Tgraph;
    void update();

    void render();

    // Handles key presses
    void handleEvent(SDL_Event e);

    void Destroy();

    void validateMovement();

    bool LoadMedia();

    // Sets the tile of the pacman
	void SetTile(Tile* newTile);

    // Sets the next tile (to which pacman will go)
	void SetNextTile(Tile* newNextTile);

    // Returns current direction of movement
    MoveDirection GetMoveDirection();

    SDL_Rect GetCollider();

	bool IsMoving();

	void Delete();
};
