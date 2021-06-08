#include "../Resources/Game/TileGraph.hpp"

#include <algorithm>
#include <iostream>
int tilDim = 32;

TileGraph::TileGraph(int h, int w)
{
	// Create a dynamic array of Tiles
	tiles = new Tile[w * h];
	cherry_text = TextureManager::LoadTexture("../Resources/cherry.bmp");
	// Set position of all tiles
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
				food.push_back(std::make_pair(x, y));
                break;
            case 0:
                tiles[x+(y*w)].SetType('w');
                break;
            default:
                break;
            }
        }
    }
	cher.w = 32;
	cher.h = 32;
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
	std::cout << x << " " << y  << "to be removed" << std::endl;
	std::vector<std::pair<int, int> >::iterator it;
	for (it = food.begin(); it != food.end(); it++){
		if (((*it).first == x / tilDim) && ((*it).second == y / tilDim)){
			food.erase(it);
			return;
		}
	}
}

