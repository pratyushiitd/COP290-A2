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
    SDL_Renderer *gameRenderer;
    bool running;
    int imgFlags;
public:
    Game();
    ~Game();
    void init(const char *title, int xpos, int ypos, int width, int height, bool flag);
    void handleEvents();
    void update();
    void render();
    void clear();
    bool isRunning();
};

#endif
