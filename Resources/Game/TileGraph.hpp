#pragma once

#include <array>
#include "Tile.hpp"


class TileGraph
{
public:
	TileGraph(int h, int w);
	~TileGraph();

	// (Re)Creates all tiles
	void Setup(int w, int h);

	// Returns tile at given position
	Tile* GetTileAt(int x, int y);

	// std::array<Tile*, 4> GetNeighbours(Tile* tile);
	// std::array<Tile*, 8> GetNeighboursDiag(Tile* tile);

private:
	Tile* tiles;
	int width;
	int height;

	int GetIndex(int x, int h);
};