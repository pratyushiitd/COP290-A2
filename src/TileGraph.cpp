#include "../Resources/Game/TileGraph.hpp"
#include <algorithm>
#include <iostream>
int tilDim = 32;
int _WIDTH = 1184 / tilDim;
int _HEIGHT = 1184 / tilDim;

TileGraph::TileGraph()
{
	// Create a dynamic array of Tiles
	tiles = new Tile[_WIDTH*_HEIGHT];

	// Set position of all tiles
	// NOTE: This could propably be also made with constructor
    int w = _WIDTH;
    int h = _HEIGHT;
    freopen("../outputs/matrix.out", "r", stdin);
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            int kind;
            tiles[x + (y*w)].SetPos(x, y);
            std::cin >> kind;
            switch (kind)
            {
            case 1:
                /* code */
                tiles[x+(y*w)].SetType('r');
                break;
            case 0:
                tiles[x+(y*w)].SetType('w');
                break;
            default:
                break;
            }
        }
    }

	width = w;
	height = h;
}

void TileGraph::Setup(int w, int h)
{
    //Recreate the TieGraph
	if (tiles != NULL)
		delete[] tiles;

	tiles = new Tile[w*h];

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			tiles[x + (y*w)].SetPos(x, y);
		}
	}

	width = w;
	height = h;
}

TileGraph::~TileGraph()
{
	delete[] tiles;
}

Tile* TileGraph::GetTileAt(int x, int y)
{
	int index = GetIndex(x / tilDim, y / tilDim);
	if (index < 0)
		return NULL;

	return &tiles[index];
}

std::array<Tile*, 4> TileGraph::GetNeighbours(Tile* tile)
{
	std::array<Tile*, 4> neighbours;

	int x = tile->GetPosition().x;
	int y = tile->GetPosition().y;

	neighbours[0] = GetTileAt(x, y + 1);		// N
	neighbours[1] = GetTileAt(x + 1, y);		// E
	neighbours[2] = GetTileAt(x, y - 1);		// S
	neighbours[3] = GetTileAt(x - 1, y);		// W

	return neighbours;
}

std::array<class Tile*, 8> TileGraph::GetNeighboursDiag(class Tile* tile)
{
	std::array<Tile*, 8> neighbours;

	int x = tile->GetPosition().x;
	int y = tile->GetPosition().y;

	neighbours[0] = GetTileAt(x, y + 1);		// N
	neighbours[1] = GetTileAt(x + 1, y);		// E
	neighbours[2] = GetTileAt(x, y - 1);		// S
	neighbours[3] = GetTileAt(x - 1, y);		// W
	neighbours[4] = GetTileAt(x + 1, y + 1);	// NE
	neighbours[5] = GetTileAt(x - 1, y + 1);	// SE
	neighbours[6] = GetTileAt(x - 1, y - 1);	// SW
	neighbours[7] = GetTileAt(x + 1, y - 1);	// NW

	return neighbours;
}

int TileGraph::GetIndex(int x, int y)
{
	if (x >= width || y >= height)
		return -1;

	if (x < 0 || y < 0)
		return -1;

	return x + y * width;
}