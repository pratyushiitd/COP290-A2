
#include "../Resources/Game/Map.hpp"
#include "../Resources/Game/Constants.hpp"
#include <iostream>
#include <fstream>

const char *background_file = "../Resources/Themes/avengers.bmp";

const char *tile_file = "../Resources/tile.bmp";

const char *mazeFile = "../outputs/matrix.out";

const char *themes[] = {"../Resources/Themes/avengers.bmp",
                        "../Resources/Themes/angrybird.bmp",
                        "../Resources/Themes/csgo.bmp",
                        "../Resources/Themes/HarryPotter.bmp"};

const char *buttonLight[] = {"../Resources/ButtonLight/Avengers.bmp",
                        "../Resources/ButtonLight/AngryBirds.bmp",
                        "../Resources/ButtonLight/CS.bmp",
                        "../Resources/ButtonLight/HarryPotter.bmp"};

const char *buttonDark[] = {"../Resources/ButtonDark/Avengers.bmp",
                        "../Resources/ButtonDark/AngryBirds.bmp",
                        "../Resources/ButtonDark/CS.bmp",
                        "../Resources/ButtonDark/HarryPotter.bmp"};

const int TILE_DIM = TILE_SIZE;

// int array_2d[Y_SIZE][X_SIZE];
int array_2d[Y_SIZE][X_SIZE] = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0},
{0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0},
{0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,0},
{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0},
{0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0},
{0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0},
{0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0},
{0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0},
{0,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0},
{0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0},
{0,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0},
{0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0},
{0,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0},
{0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0},
{0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0},
{0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
{0,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,0},
{0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0},
{0,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,0},
{0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0},
{0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0},
{0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,1,0,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,0},
{0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0},
{0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0},
{0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0},
{0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,0},
{0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0},
{0,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
bool Map::HandleTheme(SDL_Event e){
        if (e.type == SDL_KEYDOWN  && e.key.repeat == 0)
        {
            if (e.key.keysym.scancode == SDL_SCANCODE_RETURN) return true;
            switch (e.key.keysym.sym){
            case SDLK_UP:
                if (curr_press == 0) curr_press = total_themes - 1;
                else curr_press = (curr_press - 1) % total_themes;
                // std::cout << y_pos << std::endl;
                break;
            case SDLK_DOWN:
                curr_press = (curr_press + 1) % total_themes;
                // std::cout << y_pos << std::endl;
                break;
            default:
                break;
            }
        }
    return false;
}
void Map::display(SDL_Renderer* ren){
    backGround = TextureManager::LoadTexture(themes[curr_press]);
    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(ren);
    SDL_RenderCopy(ren, backGround, NULL, NULL);
    for(int i = 0; i < total_themes; i++){
        Button.y = BUTTON_SPACING + (BUTTON_SPACING + BUTTON_HEIGHT)*i;
        if (i == curr_press) SDL_RenderCopy(ren, TextureManager::LoadTexture(buttonDark[curr_press]), NULL, &Button);
        else SDL_RenderCopy(ren, TextureManager::LoadTexture(buttonLight[i]), NULL, &Button);
    }
    SDL_RenderPresent(ren);
}
void Map::LoadMaze(){
    // freopen(mazeFile, "r", stdin);
    // //std::cout << Y_SIZE << " " << X_SIZE << std::endl;
    // for (int i = 0; i < (int)Y_SIZE; i++)
    // {
    //     for (int j = 0; j < (int)X_SIZE; j++)
    //     {
    //         int kind;
    //         array_2d[i][j] = kind;
    //     }
    // }
}
Map::Map(){
    src.x = src.h = src.w = src.y = 0;
    dest.x = dest.y = 0;
    dest.h = dest.w = TILE_DIM;
    backGround = TextureManager::LoadTexture(background_file);
    curr_press = 0;
    TileTexture = TextureManager::LoadTexture(tile_file);
    Button.w = BUTTON_WIDTH; Button.h = BUTTON_HEIGHT;
    Button.x = (SCREEN_WIDTH - BUTTON_WIDTH) / 2;
    total_themes = THEME_COUNT;
}

void Map::DrawMap(SDL_Renderer* ren){
    SDL_RenderCopy(ren, backGround, NULL, NULL);
    //std::cout << x_size << " " << y_size << std::endl;
    for (unsigned int i = 0; i < Y_SIZE; i++) {
        for (unsigned int j = 0; j < X_SIZE; j++) {
            dest.x = TILE_DIM * j;
            dest.y = TILE_DIM * i;
                        //std::cout << array_2d[i][j] << " ";

            if (!array_2d[i][j]){
                SDL_RenderCopy(ren, TileTexture, NULL, &dest);
            }
        }
        //std::cout << std::endl;
    }
    // std::cout << std::endl;
}

Map::~Map(){}

