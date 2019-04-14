
#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char * texturesheet, SDL_Renderer * renderer, int x, int y)
{
    xpos = x;
    ypos = y;
    rend = renderer;
    texture = TextureManager::load(texturesheet, rend);
}

GameObject::~GameObject()
{}

void GameObject::update()
{
    xpos++;
    ypos++;

    src.h = src.w = 360;
    src.x = src.y = 0;

    dest.x = xpos;
    dest.y = ypos;
    dest.w = dest.h = 64;
}

void GameObject::render()
{
    SDL_RenderCopy(rend, texture, &src, &dest);
}