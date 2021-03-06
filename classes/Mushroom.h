
#ifndef PLATFORMER_MUSHROOM_H
#define PLATFORMER_MUSHROOM_H

#include "Game.h"


class Mushroom {

public:
    Mushroom(const char * texturesheet, int x, int y);
    void render();
    void sound();
    bool isActive;
    bool checkCollision(SDL_Rect rect);

private:
    SDL_Texture * texture;
    SDL_Rect src, dest;

    Uint8 * sound_buf;
    Uint32 sound_len;
    SDL_AudioDeviceID device;

};


#endif //PLATFORMER_MUSHROOM_H
