#ifndef _OBSTACLE__H
#define _OBSTACLE__H

#pragma once


#include "graphics.h"
#include "texture.h"
#include "dino.h"

#include <bits/stdc++.h>
using namespace std;

class Obs : Texture {
public:
    Obs(int x, int y);
    ~Obs();
    bool loadFromFile(string path, SDL_Renderer* renderer);

    float getX() {return obs_x;};
    float get() {return obs_y;};

    SDL_Rect getCollision() const {return collision;};
    void render(SDL_Renderer* renderer, int camera_x);

private:
    float obs_x;
    float obs_y;

    SDL_Rect collision;

};

#endif // _OBSTACLE__H
