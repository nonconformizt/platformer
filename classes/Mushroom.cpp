
#include "Mushroom.h"
#include "TextureManager.h"
#include "math.h"

Mushroom::Mushroom(const char * texturesheet, int x, int y)
{
    isActive = true;

    dest.x = x;
    dest.y = y;
    src.x = src.y = 0;
    src.w = src.h = 360;
    dest.w = dest.h = 32;

    texture = TextureManager::load(texturesheet);
}

void Mushroom::render()
{
    SDL_RenderCopy(Game::rend, texture, &src, &dest);
}

bool Mushroom::checkCollision(SDL_Rect rect)
{
    int distance = (int) sqrt(
             (rect.x + rect.w/2 - dest.x - 16)*
             (rect.x + rect.w/2 - dest.x - 16) +
             (rect.y + rect.h/2 - dest.y - 16)*
             (rect.y + rect.h/2 - dest.y - 16)
            );

    return distance <= 64;
}

