#ifndef Game_hpp
#define Game_hpp

#include<SDL2/SDL.h> 
#include <stdio.h>
#include <string>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <fstream> 

class Game
{
private:
    SDL_Window *gameWindow;
    bool running;
    int imgFlags;
    int count;
public:
    static SDL_Renderer *gameRenderer;
    Game();
    ~Game();
    void init(const char *title, int xpos, int ypos, int width, int height, bool flag);
    void handleEvents();
    void update();
    void render_from_Texture(SDL_Texture *texture);
    void clear();
    bool isRunning();
};

#endif
