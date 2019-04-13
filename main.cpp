#include "classes/Game.h"

Game * game = nullptr;

int main(int argc, char *argv[])
{
    Uint32 frame_start;
    int frame_time;

    game = new Game();
    game->init("Simple platformer", WINDOW_W, WINDOW_H, false);

    while (game->running())
    {
        frame_start = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frame_time = SDL_GetTicks() - frame_start;
        if (frame_time < DELAY)
            SDL_Delay( (Uint32) DELAY - frame_time );
    }

    game->clean();
    return 0;
}
