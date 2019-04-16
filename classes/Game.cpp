#include <cstring>
#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Mushroom.h"
#include "Coin.h"
#include "Map.h"

SDL_Renderer * Game::rend = nullptr;

Map * map = nullptr;

GameObject * player = nullptr;

Mushroom * mush[2];
int mushrooms_x[2] = { WINDOW_W - 320, 192 };
int mushrooms_y[2] = { 192, 224 };
int mushrooms_count = 0;

Coin * coins[4];
int coins_x[4] = { 100, 34, 231, 444 };
int coins_y[4] = { 342, 65, 645, 230 };
int coins_count = 0;


Game::Game()
{
    is_down = is_up = is_left = is_right = false;
}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
    int i;
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
    for (i = 0; i < 2; i++)
        mush[i] = new Mushroom("./assets/mushroom.png", mushrooms_x[i], mushrooms_y[i]);
    for (i = 0; i < 4; i++)
        coins[i] = new Coin("./assets/coin.png", coins_x[i], coins_y[i]);
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
                if (mush[i]->isActive && mush[i]->checkCollision(player->get_rect())) {
                    mush[i]->sound();
                    mush[i]->isActive = false;
                    mushrooms_count++;
                }
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

    player->animated = !is_right && !is_left && !is_up && !is_down;

    for (int i = 0; i < 4; ++i)
        if (coins[i]->isActive && coins[i]->checkCollision(player->get_rect())) {
            coins[i]->sound();
            coins[i]->isActive = false;
            coins_count++;
        }

    // check win
    SDL_Rect player_rect = player->get_rect();
    int pl_col = (player_rect.x) / 32;
    int pl_row = (player_rect.y + player_rect.h - 2) / 32;

    if (pl_row == 26 && (pl_col == 1 || pl_col == 2) ) {
        char message[256] = "You win!\n === COLLECTED COINS: ";
        char buffer[256];
        itoa(coins_count, buffer, 10);
        strcat(message, buffer);
        strcat(message, " ===\n=== KILLED ENEMIES: ");
        itoa(mushrooms_count, buffer, 10);
        strcat(message, buffer);
        strcat(message, " ===\n");

        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Congratulations!", message, nullptr);
        is_running = false;
    }

    player->update();
}

void Game::render()
{
    SDL_RenderClear(rend);

    map->draw();
    for (int i = 0; i < 2; ++i)
        if (mush[i]->isActive)
            mush[i]->render();
    for (int i = 0; i < 4; ++i)
        if (coins[i]->isActive)
            coins[i]->render();
    player->render();

    SDL_RenderPresent(rend);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(rend);
    SDL_Quit();
}