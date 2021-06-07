#pragma once
#include "Movedirection.hpp"
#include "TileGraph.hpp"

class GameObject
{
private:
    int x_pos;
    int y_pos;
    SDL_Texture* objTexture;
    SDL_Rect src, dest;
    MoveDirection curr_Dir = MOVE_STILL;
    MoveDirection next_Dir = MOVE_STILL;
    static const int Width = 32;
	static const int Height = 32;
	static const int MoveFrames = 2;
    static const int Velocity = 2;

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

    // // Returns position
	// SDL_Point GetPosition();
    // // Returns pacman's tile
	// Tile* GetTile();

	// // Returns the tile which pacman is going to
	// Tile* GetNextTile();

	// Returns true if pacman is moving
	bool IsMoving();

	void Delete();
};
