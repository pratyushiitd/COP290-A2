#pragma once

#include <array>
#include "Tile.hpp"
#include <vector>

class TileGraph
{
public:
	TileGraph(int h, int w);
	~TileGraph();

	// (Re)Creates all tiles
	void Setup(int w, int h);

	// Returns tile at given position
	Tile* GetTileAt(int x, int y);
	void render_food();
	// std::array<Tile*, 4> GetNeighbours(Tile* tile);
	// std::array<Tile*, 8> GetNeighboursDiag(Tile* tile);
	void remove_food(int x, int y);
private:
	Tile* tiles;
	SDL_Rect cher;
	int width;
	int height;
	std::vector<std::pair<int, int> > food;
	SDL_Texture* cherry_text;
	int GetIndex(int x, int h);
};