#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h> 
#include <stdio.h>
#include <string>
// #include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <fstream> 
#include "Constants.hpp"

class Game
{
private:
    SDL_Window *gameWindow;
    int count;
public:
    static SDL_Renderer *gameRenderer;
        bool running;
    Game();
    ~Game();
    void init(const char *title, int xpos, int ypos, int width, int height, bool flag);
    void handleEvents();
    void update();
    void render();
    void clear();
    bool isRunning();
    void closeRequest();
};

#endif
