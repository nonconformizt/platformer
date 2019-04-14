
#ifndef PLATFORMER_GAMEOBJECT_H
#define PLATFORMER_GAMEOBJECT_H

#include "Game.h";

class GameObject {

public:
    GameObject(const char * texturesheet, SDL_Renderer * renderer, int x, int y);
    ~GameObject();

    void update();
    void render();

private:

    int xpos, ypos;

    SDL_Texture * texture;
    SDL_Rect dest, src;
    SDL_Renderer * rend;

};


#endif //PLATFORMER_GAMEOBJECT_H
