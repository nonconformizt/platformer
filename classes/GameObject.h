
#ifndef PLATFORMER_GAMEOBJECT_H
#define PLATFORMER_GAMEOBJECT_H

#include "Game.h"

#define SPEED 2

class GameObject {

public:
    GameObject(const char * texturesheet, int x, int y);
    ~GameObject();

    void update();
    void render();
    void move_down() { ypos += SPEED; }
    void move_up() { ypos -= SPEED; }
    void move_right() { xpos += SPEED; }
    void move_left() { xpos -= SPEED; }

    SDL_Rect get_step_down() { SDL_Rect r = { xpos, ypos + SPEED, dest.w, dest.h }; return r; }
    SDL_Rect get_step_up() { SDL_Rect r = { xpos, ypos - SPEED, dest.w, dest.h }; return r; }
    SDL_Rect get_step_right() { SDL_Rect r = { xpos + SPEED, ypos, dest.w, dest.h }; return r; }
    SDL_Rect get_step_left() { SDL_Rect r = { xpos - SPEED, ypos, dest.w, dest.h }; return r; }


private:
    int xpos, ypos;
    SDL_Texture * texture;
    SDL_Rect dest, src;

};


#endif //PLATFORMER_GAMEOBJECT_H
