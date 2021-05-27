#include<SDL2/SDL.h> 
#include <stdio.h>
#include <string>
#include <SDL2/SDL_image.h> //For loading images of other format

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;


//The window renderer
SDL_Renderer* gRenderer = NULL;
//The window we'll be rendering to
SDL_Window* gWindow = NULL;
SDL_Texture* LoadTexture(std :: string path);
bool init();
bool loadMedia();
void close();

bool init(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL couldn't get initialized! SDL Error : %s\n", SDL_GetError());
        return false;
    }
    else
    {
        gWindow = SDL_CreateWindow( "Start Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        //We don't care where the window is created, put SDL_WINDOWPOS_UNDEFINED for the x and y position.
        //SDL_WINDOW_SHOWN makes sure the window is shown when it is created.
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            return false;
        }
        else
        {
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL){
                printf("Renderer could not be initialized, SDL Error %s .\n", SDL_GetError());
                return false;
            }
            else{
                int imgFlags = IMG_INIT_JPG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    return false;
                }
            }
        }
    }
    return true;
}
bool loadMedia(){
    return true;
}

int main(int argc, char* argv[]){
    //While application is running
    bool _init_ = init();
    if (!_init_){
        printf(
            "Initialization Failed!!\n"
        );
        return -1;
    }
    bool _load_ = loadMedia();
    if (!_load_){
        printf( 
            "Media Loading Failed!!\n"
        );
        return -1;
    }
    SDL_Event e;
    bool quit = false;
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gRenderer );
        //Render red filled quad
        SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );        
        SDL_RenderFillRect( gRenderer, &fillRect );
        SDL_Rect fillRect2 = {SCREEN_WIDTH / 6, SCREEN_HEIGHT / 3, SCREEN_WIDTH * 2 / 3 , SCREEN_HEIGHT / 3};
        SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF );
        SDL_RenderDrawRect(gRenderer, &fillRect2);
        SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF );
        SDL_RenderDrawLine( gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 );
        //Draw vertical line of yellow dots
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        for( int i = 0; i < SCREEN_HEIGHT; i += 16 )
        {
            SDL_RenderDrawPoint( gRenderer, SCREEN_WIDTH / 2, i);
        }

        //Update screen
        SDL_RenderPresent( gRenderer );
    }
}