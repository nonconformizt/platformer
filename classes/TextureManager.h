
#ifndef PLATFORMER_TEXMANAGER_H
#define PLATFORMER_TEXMANAGER_H

#include "Game.h"

class TextureManager {

public:
    static SDL_Texture * load (const char * fname);
    static void draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest);
};


#endif //PLATFORMER_TEXMANAGER_H
