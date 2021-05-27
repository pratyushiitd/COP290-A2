#include<SDL2/SDL.h>
#include <stdio.h>


const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;
SDL_Window* window = NULL;
SDL_Surface* surface = NULL;

//The image we will load and show on the screen
SDL_Surface* gImgShow = NULL;

bool SDL_init(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL couldn't get initialized! SDL Error : %s\n", SDL_GetError());
        return false;
    }
    else
    {
        window = SDL_CreateWindow( "Start Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        //We don't care where the window is created, put SDL_WINDOWPOS_UNDEFINED for the x and y position.
        //SDL_WINDOW_SHOWN makes sure the window is shown when it is created.
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            return false;
        }
        else
        {
            //Get window surface to draw on it
            surface = SDL_GetWindowSurface( window );
            return true;
        }
    }
}
bool loadMedia()
{
    //Load splash image
    gImgShow = SDL_LoadBMP( "../resources/sheldon.bmp" );
    if( gImgShow== NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "sheldon.bmp", SDL_GetError() );
        return false;
    }

    return true;
}
void close()
{
    //Deallocate surface
    SDL_FreeSurface( gImgShow );
    gImgShow = NULL;

    //Destroy window
    SDL_DestroyWindow( window );
    window = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}
int main(int argc, char*argv[]){

    if (!SDL_init()){
        printf("Initialization Failed\n");
        return -1;
    }
    printf("Initialization Success\n");
    
    if (!loadMedia()){
        printf("Media Loading Failed\n");
        return -1;
    }
    SDL_Event e;
    bool quit = false;

    while (!quit){
        while (SDL_PollEvent(&e) != 0){
            if (e.type == SDL_QUIT){
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN){
                printf("Keydown detected\n");
            }
        }
    }
    
    SDL_BlitSurface ( 
                    gImgShow , NULL,  /*Source*/
                    surface , NULL   /*Destination*/
                    );
    //take a source surface and stamps a copy of it onto the destination surface.

    SDL_UpdateWindowSurface( window );
    SDL_Delay( 2000 );
    //Quit SDL subsystems
    close();
    return 0;
}