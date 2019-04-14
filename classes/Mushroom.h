
#ifndef PLATFORMER_MUSHROOM_H
#define PLATFORMER_MUSHROOM_H

#include "Game.h"


class Mushroom {

public:
    Mushroom(const char * texturesheet, int x, int y);
    void render();
    bool isActive;
    bool checkCollision(SDL_Rect rect);

private:
    int xpos, ypos;
    SDL_Texture * texture;
    SDL_Rect dest, src;

};


#endif //PLATFORMER_MUSHROOM_H
