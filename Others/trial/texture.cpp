#include<SDL2/SDL.h> 
#include <stdio.h>
#include <string>
#include <SDL2/SDL_image.h> //For loading images of other format

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

//Current Displayed Texture
SDL_Texture* gTexture = NULL;
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
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
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

SDL_Texture* LoadTexture(std :: string path){

    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());

    if (loadedSurface == NULL){
        printf("COuld not load path%s, SDL Error : %s !!!\n", path.c_str(), SDL_GetError());
    }
    else{
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL){
            printf("Could not initilize new Texture from Surface!!\n");
        }
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

bool loadMedia(){
    gTexture = LoadTexture("../resources/sheldon.jpg");
    if (gTexture == NULL){
        printf("Failed to load Media. Texture could not be loaded!!\n");
        return false;
    }
    return true;
}
void close()
{
    //Free loaded image
    SDL_DestroyTexture( gTexture );
    gTexture = NULL;

    //Destroy window    
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}


int main(int argc, char* argv[]){
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
    while(!quit){
        while ( !SDL_PollEvent (&e) ){
            if (e.type == SDL_QUIT){
                quit = true;
            }
        }
        //Clear screen
            SDL_RenderClear( gRenderer );

            //Render texture to screen
            SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );

            //Update screen
            SDL_Rect topLeftViewport;
            topLeftViewport.x = 0;
            topLeftViewport.y = 0;
            topLeftViewport.w = SCREEN_WIDTH / 2;
            topLeftViewport.h = SCREEN_HEIGHT / 2;
            SDL_RenderSetViewport( gRenderer, &topLeftViewport );
            
            //Render texture to screen
            SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
            SDL_Rect topRightViewport;
            topRightViewport.x = SCREEN_WIDTH / 2;
            topRightViewport.y = 0;
            topRightViewport.w = SCREEN_WIDTH / 2;
            topRightViewport.h = SCREEN_HEIGHT / 2;
            SDL_RenderSetViewport( gRenderer, &topRightViewport );
            
            //Render texture to screen
            SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
            SDL_Rect bottomViewport;
            bottomViewport.x = 0;
            bottomViewport.y = SCREEN_HEIGHT / 2;
            bottomViewport.w = SCREEN_WIDTH;
            bottomViewport.h = SCREEN_HEIGHT / 2;
            SDL_RenderSetViewport( gRenderer, &bottomViewport );
            
            //Render texture to screen
            SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
            //Update screen
            SDL_RenderPresent( gRenderer );
    }
    return 0;
}