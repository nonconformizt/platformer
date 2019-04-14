
#ifndef PLATFORMER_MAP_H
#define PLATFORMER_MAP_H

#include "Game.h"

#define COLS 30
#define ROWS 26

class Map {

public:

    Map();
    ~Map();

    void load(int arr[26][30]);
    void draw();
    bool checkCollision(SDL_Rect rect);

private:

    SDL_Rect src, dest;
    SDL_Texture * grass, * stone;

    int map[26][30];

};


#endif //PLATFORMER_MAP_H
