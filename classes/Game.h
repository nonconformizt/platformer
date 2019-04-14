
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define WINDOW_W 960
#define WINDOW_H 832
#define DELAY 16

class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    bool running() { return is_running; }
    void render();
    void clean();

    static SDL_Renderer *rend;

private:
    bool is_running = false;

    // running controls
    bool is_down, is_up, is_left, is_right;

    SDL_Window * window;

};


#endif //PLATFORMER_GAME_H
