#include "../Resources/Game/TileGraph.hpp"

#include <algorithm>
#include <iostream>
int tilDim = TILE_SIZE;

TileGraph::TileGraph(int y_size, int x_size)
{
	// Create a dynamic array of Tiles
	tiles = new Tile[x_size * y_size];
	cherry_text = TextureManager::LoadTexture("../Resources/cherry.bmp");
	// Set position of all tiles
    freopen("../outputs/matrix.out", "r", stdin);
    for (int y = 0; y < y_size; y++)
    {
        for (int x = 0; x < x_size; x++)
        {
            int kind;
            tiles[x + (y*x_size)].SetPos(x, y);
            std::cin >> kind;
            switch (kind)
            {
            case 1:
                /* code */
                tiles[x+(y*x_size)].SetType('r');
				food.push_back(std::make_pair(x, y));
                break;
            case 0:
                tiles[x+(y*x_size)].SetType('w');
                break;
            default:
                break;
            }
        }
    }
	cher.w = tilDim;
	cher.h = tilDim;
	width = x_size;
	height = y_size;
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

int TileGraph::GetIndex(int x_pix, int y_pix)
{
	int x_til = x_pix / tilDim;
	int y_til = y_pix / tilDim;
	return x_til + y_til * width;
}

void TileGraph::render_food()
{
	for (int y = 0; y < food.size(); y++){
		cher.x = (food[y].first) * tilDim;
		cher.y = (food[y].second) * tilDim;
		SDL_RenderCopy(Game::gameRenderer, cherry_text, NULL, &cher);
	}
}

void TileGraph::remove_food(int x, int y)
{
	//std::cout << x << " " << y  << "to be removed" << std::endl;
	std::vector<std::pair<int, int> >::iterator it;
	for (it = food.begin(); it != food.end(); it++){
		if (((*it).first == x / tilDim) && ((*it).second == y / tilDim)){
			food.erase(it);
			return;
		}
	}
}

