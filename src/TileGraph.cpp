#include "../Resources/Game/TileGraph.hpp"

#include <algorithm>
#include <iostream>
int tilDim = 32;

TileGraph::TileGraph(int h, int w)
{
	// Create a dynamic array of Tiles
	tiles = new Tile[w * h];

	// Set position of all tiles
	// NOTE: This could propably be also made with constructor
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


TileGraph::~TileGraph()
{
	delete[] tiles;
}

Tile* TileGraph::GetTileAt(int x, int y)
{
	int index = GetIndex(x, y);
	if (index < 0)
		return NULL;

	return &tiles[index];
}

// std::array<Tile*, 4> TileGraph::GetNeighbours(Tile* tile)
// {
// 	std::array<Tile*, 4> neighbours;

// 	int x = tile->GetPosition().x;
// 	int y = tile->GetPosition().y;

// 	neighbours[0] = GetTileAt(x, y + 1);		// N
// 	neighbours[1] = GetTileAt(x + 1, y);		// E
// 	neighbours[2] = GetTileAt(x, y - 1);		// S
// 	neighbours[3] = GetTileAt(x - 1, y);		// W

// 	return neighbours;
// }

// std::array<class Tile*, 8> TileGraph::GetNeighboursDiag(class Tile* tile)
// {
// 	std::array<Tile*, 8> neighbours;

// 	int x = tile->GetPosition().x;
// 	int y = tile->GetPosition().y;

// 	neighbours[0] = GetTileAt(x, y + 1);		// N
// 	neighbours[1] = GetTileAt(x + 1, y);		// E
// 	neighbours[2] = GetTileAt(x, y - 1);		// S
// 	neighbours[3] = GetTileAt(x - 1, y);		// W
// 	neighbours[4] = GetTileAt(x + 1, y + 1);	// NE
// 	neighbours[5] = GetTileAt(x - 1, y + 1);	// SE
// 	neighbours[6] = GetTileAt(x - 1, y - 1);	// SW
// 	neighbours[7] = GetTileAt(x + 1, y - 1);	// NW

// 	return neighbours;
// }

int TileGraph::GetIndex(int x_pix, int y_pix)
{
	int x_til = x_pix / tilDim;
	int y_til = y_pix / tilDim;
	return x_til + y_til * width;
}