
#include "GameObject.h"
#include "TextureManager.h"
#include "Map.h"

GameObject::GameObject(const char * texturesheet, int x, int y)
{
    xpos = x;
    ypos = y;
    texture = TextureManager::load(texturesheet);

//    src.w = 180;
    src.w = 360;
//    src.h = 318;
    src.h = 360;
//    dest.w = 36;
    dest.w = 72;
    dest.h = 72;

    animated = true;
}

GameObject::~GameObject()
{}

void GameObject::update()
{
    // animate
    if (animated)
        src.x = src.w * int((SDL_GetTicks() / 150) % 4 );
    else
        src.x = 0;

    src.y = 0;
    dest.x = xpos;
    dest.y = ypos;
}

void GameObject::render()
{
    SDL_RenderCopy(Game::rend, texture, &src, &dest);
}