#include<SDL2/SDL.h> 
#include <stdio.h>
#include <string>
#include <SDL2/SDL_image.h> //For loading images of other format


const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;


//Key press surfaces constants
enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT, //0
    KEY_PRESS_SURFACE_UP, //1
    KEY_PRESS_SURFACE_DOWN, //2
    KEY_PRESS_SURFACE_LEFT, //3
    KEY_PRESS_SURFACE_RIGHT, //4
    KEY_PRESS_SURFACE_TOTAL //5
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image
SDL_Surface* loadSurface( std::string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
    
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];

//Current displayed image
SDL_Surface* gCurrentSurface = NULL;


int main(int argc, char*argv[]){
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
    gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];

    SDL_Rect Stretch_rect;
    Stretch_rect.x = 0;
    Stretch_rect.y = 0;
    Stretch_rect.w = SCREEN_WIDTH;
    Stretch_rect.h = SCREEN_HEIGHT;
    while(!quit){
        while(SDL_PollEvent(&e)){

            if (e.type == SDL_QUIT){
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN){
                switch (e.key.keysym.sym){
                case SDLK_UP:
                    gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
                    break;
                case SDLK_DOWN:
                    gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
                    break;
                case SDLK_LEFT:
                    gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
                    break;
                case SDLK_RIGHT:
                    gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
                    break;
                default:
                    gCurrentSurface = gKeyPressSurfaces [KEY_PRESS_SURFACE_DEFAULT];
                    break;
                }
            }
            
        }
        SDL_BlitScaled ( 
                    gCurrentSurface, NULL,  /*Source*/
                    gScreenSurface , &Stretch_rect   /*Destination*/
                    );
        SDL_UpdateWindowSurface(gWindow);
        SDL_Delay(100);
    }
    close();
    return 0;
}
SDL_Surface* loadSurface( std::string path )
{
    //Load image at specified path
    //SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() ); //FOr loading BMP
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() ); //Load other than BMP, as described by Image FLag


    SDL_Surface* OptimizedSurface = NULL; 
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }else{
        OptimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
        //convert it to the same format as the screen so no conversion needs to be done on blit
        if (OptimizedSurface == NULL){
            printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        SDL_FreeSurface(loadedSurface);
    }

    return OptimizedSurface;
}

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
            //Get window surface to draw on it
            //gScreenSurface = SDL_GetWindowSurface( gWindow );
            //return true;

            //Initialize PNG loading
            //int imgFlags = IMG_INIT_PNG;
            int imgFlags = IMG_INIT_JPG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                return false;
            }
            else
            {
                //Get window surface
                gScreenSurface = SDL_GetWindowSurface( gWindow );
                return true;
            }

        }
    }
}

bool loadMedia(){
    bool success = true;
    //Load default surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface( "../resources/sheldon.jpg" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }

    gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface( "../resources/up.jpg" );
    if (gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL)
    {
        printf( "Failed to load up Image!\n" );
        success = false;
    }

    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] = loadSurface( "../resources/down.jpg" );
    if (gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL)
    {
        printf( "Failed to load down Image!\n" );
        success = false;
    }
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface( "../resources/left.jpg" );
    if (gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL)
    {
        printf( "Failed to load left Image!\n" );
        success = false;
    }
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface( "../resources/right.jpg" );
    if (gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL)
    {
        printf( "Failed to load right Image!\n" );
        success = false;
    }
    return success;
}
void close()
{
    //Deallocate surface
    SDL_FreeSurface( gScreenSurface );
    gScreenSurface = NULL;

    SDL_FreeSurface( gCurrentSurface );
    gCurrentSurface = NULL;
    for( int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i )
	{
		SDL_FreeSurface( gKeyPressSurfaces[ i ] );
		gKeyPressSurfaces[ i ] = NULL;
	}
    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}