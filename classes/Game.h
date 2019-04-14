
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define WINDOW_W 800
#define WINDOW_H 600
#define DELAY 16

class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    bool running() { return isRunning; }
    void render();
    void clean();

private:
    bool isRunning = false;
    int cnt = 0;
    SDL_Window *window;
    SDL_Renderer *rend;
};


#endif //PLATFORMER_GAME_H
