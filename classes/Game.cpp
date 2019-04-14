#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Mushroom.h"
#include "Map.h"

SDL_Renderer * Game::rend = nullptr;

Map * map = nullptr;

GameObject * player = nullptr;

Mushroom * mush[10];
int mushrooms_x[2] = { WINDOW_W - 320, 192 };
int mushrooms_y[2] = { 192, 224 };


Game::Game()
{
    is_down = is_up = is_left = is_right = false;
}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
    Uint32 flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        rend = SDL_CreateRenderer(window, -1, 0);
        if (!rend)
            return;

        SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);

        is_running = true;
    }

    player = new GameObject("./assets/player.png", WINDOW_W - 80, 10);
    for (int i = 0; i < 2; ++i)
        mush[i] = new Mushroom("./assets/mushroom.png", mushrooms_x[i], mushrooms_y[i]);
    map = new Map();
}

void Game::handleEvents()
{
    SDL_Event e;

    while(SDL_PollEvent(&e))
        if (e.type == SDL_QUIT)
            is_running = false;
        else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
            is_running = false;
        else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
            for (int i = 0; i < 2; ++i)
                if (mush[i]->isActive && mush[i]->checkCollision(player->get_rect()))
                    mush[i]->isActive = false;
                // increment counter
        }
        else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_s)
            is_down = true;
        else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_w)
            is_up = true;
        else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_d)
            is_right = true;
        else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_a)
            is_left = true;
        else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_s)
            is_down = false;
        else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_w)
            is_up = false;
        else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_d)
            is_right = false;
        else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_a)
            is_left = false;
}

void Game::update()
{

    if (is_down)
        if (!map->checkCollision(player->get_step_down()))
            player->move_down();
    if (is_up)
        if (!map->checkCollision(player->get_step_up()))
            player->move_up();
    if (is_left)
        if (!map->checkCollision(player->get_step_left()))
            player->move_left();
    if (is_right)
        if (!map->checkCollision(player->get_step_right()))
            player->move_right();

    player->update();
}

void Game::render()
{
    SDL_RenderClear(rend);
    map->draw();
    player->render();
    for (int i = 0; i < 2; ++i)
        if (mush[i]->isActive)
            mush[i]->render();
    SDL_RenderPresent(rend);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(rend);
    SDL_Quit();
}