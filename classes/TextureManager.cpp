#include "TextureManager.h"

SDL_Texture * TextureManager::load(const char *fname, SDL_Renderer * rend)
{
    SDL_Surface * tmp = IMG_Load(fname);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(rend, tmp);
    SDL_FreeSurface(tmp);
    return texture;
}