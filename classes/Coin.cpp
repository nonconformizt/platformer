
#include "Coin.h"
#include "TextureManager.h"
#include "math.h"

Coin::Coin(const char * texturesheet, int x, int y)
{
    isActive = true;

    dest.x = x;
    dest.y = y;

    dest.w = dest.h = 20;
    src.w = src.h = 30;
    src.x = src.y = 0;

    texture = TextureManager::load(texturesheet);

    SDL_AudioSpec sound_spec;
    SDL_LoadWAV("./assets/collect.wav", &sound_spec, &sound_buf, &sound_len);
    // open audio device
    device = SDL_OpenAudioDevice(nullptr, 0, &sound_spec, nullptr, 0);
}

void Coin::update()
{
    src.x = src.w * int((SDL_GetTicks() / 150) % 6 );
}

void Coin::render()
{
    SDL_RenderCopy(Game::rend, texture, &src, &dest);
}

bool Coin::checkCollision(SDL_Rect rect)
{
    int c_center_x = dest.x + dest.w / 2;
    int c_center_y = dest.y + dest.h / 2;

    int pl_center_x = rect.x + rect.w / 2;
    int pl_center_y = rect.y + rect.h / 2;

    return sqrt((pl_center_x - c_center_x)*(pl_center_x - c_center_x) + (pl_center_y - c_center_y)*(pl_center_y - c_center_y)) <= 30;
}

void Coin::sound()
{
    SDL_ClearQueuedAudio(device);
    SDL_QueueAudio(device, sound_buf, sound_len);
    SDL_PauseAudioDevice(device, 0);
}
