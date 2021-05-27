#include<SDL2/SDL.h> 
#include <stdio.h>
#include <string>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <fstream> 

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* texture = NULL;
SDL_Texture* LoadTexture(std :: string path);
void initialize();
void close();
const int SCREEN_WIDTH = 940;
const int SCREEN_HEIGHT = 940;
const int x_width = 47;
const int y_width = 47;
int array_2d[x_width][y_width];
const int TILE_DIM = 32;
int main(int argc, char* argv[]){
    initialize();
    //bool inGame = true;
    //SDL_Event e;
    // while(inGame){
    //     while ( !SDL_PollEvent(&e) ){
    //         if (e.type == SDL_QUIT) inGame = false;
    //     }
    //     SDL_RenderClear(renderer);
    //     texture = LoadTexture("../Resources/LOR.jpg");
    //     if (texture == NULL){
    //         printf("Failed to load Media. Texture could not be loaded!!\n");
    //         return -1;
    //     }
    //     SDL_RenderCopy( renderer, texture, NULL, NULL );
    //     SDL_RenderPresent(renderer);
    // }
    SDL_RenderClear(renderer);
    texture = LoadTexture("../Resources/LOR.jpg");
    if (texture == NULL){
        printf("Failed to load Media. Texture could not be loaded!!\n");
        return -1;
    }
    SDL_RenderCopy( renderer, texture, NULL, NULL );
    SDL_Surface* tile_sur = SDL_LoadBMP("../Resources/tile.bmp");
    SDL_Texture* tile_txt = SDL_CreateTextureFromSurface(renderer, tile_sur);
    SDL_FreeSurface(tile_sur);
    tile_sur = NULL;
    SDL_Rect rect;
    rect.w = TILE_DIM;
    rect.h = TILE_DIM;
    std::ifstream file("../outputs/matrix.out");

    for (unsigned int i = 0; i < y_width; i++) {

        for (unsigned int j = 0; j < x_width; j++) {
            file >> array_2d[i][j];
            //std::cout << array_2d[i][j] << " ";
            rect.x = TILE_DIM * j;
            rect.y = TILE_DIM * i;
            if (!array_2d[i][j]){
                SDL_RenderCopy(renderer, tile_txt, NULL, &rect);
            }
        }
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(5000);
    close();
}

void initialize(){
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("SDL couldn't get initialized! SDL Error : %s\n", SDL_GetError());
        return ;
    }
    else
    {
        window = SDL_CreateWindow( "Start Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            return ;
        }
        else
        {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == NULL){
                printf("Renderer could not be initialized, SDL Error %s .\n", SDL_GetError());
                return ;
            }
            else{
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                int imgFlags = IMG_INIT_JPG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    return ;
                }
            }
        }
    }
    return;
}
SDL_Texture* LoadTexture(std :: string path){

    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());

    if (loadedSurface == NULL){
        printf("Could not load path%s, SDL Error : %s !!!\n", path.c_str(), SDL_GetError());
    }
    else{
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == NULL){
            printf("Could not initilize new Texture from Surface!!\n");
        }
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}
void close()
{
    //Free loaded image
    SDL_DestroyTexture( texture );
    texture = NULL;

    //Destroy window    
    SDL_DestroyWindow( window );
    window = NULL;
    SDL_DestroyRenderer( renderer );
    renderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}