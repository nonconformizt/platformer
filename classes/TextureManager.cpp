#include "TextureManager.h"

SDL_Texture * TextureManager::load(const char *fname)
{
    SDL_Surface * tmp = IMG_Load(fname);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(Game::rend, tmp);
    SDL_FreeSurface(tmp);
    return texture;
}

void TextureManager::draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Game::rend, tex, &src, &dest);
}