
#include "GameObject.h"
#include "TextureManager.h"
#include "Map.h"

GameObject::GameObject(const char * texturesheet, int x, int y)
{
    xpos = x;
    ypos = y;
    texture = TextureManager::load(texturesheet);

    src.w = 180;
    src.h = 318;
    dest.w = 36;
    dest.h = 64;
}

GameObject::~GameObject()
{}

void GameObject::update()
{
    src.x = 0;
    src.y = 0;

    dest.x = xpos;
    dest.y = ypos;
}

void GameObject::render()
{
    SDL_RenderCopy(Game::rend, texture, &src, &dest);
}