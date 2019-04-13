
#ifndef PLATFORMER_TEXMANAGER_H
#define PLATFORMER_TEXMANAGER_H

#include "Game.h"

class TextureManager {

public:
    static SDL_Texture * load (const char * fname, SDL_Renderer * rend);

};


#endif //PLATFORMER_TEXMANAGER_H
