#ifndef _OBSTACLE__H
#define _OBSTACLE__H

#pragma once

#include "define.h"
#include "graphics.h"
#include "texture.h"
#include "dino.h"

#include <bits/stdc++.h>
using namespace std;

class Obs : Texture {
public:
    Obs();
    ~Obs();
    bool loadFromFile(string path, SDL_Renderer* renderer);
    void handleMove ();
    void handleInput (SDL_Event* event);
    void update();
    float get_x() {return obs_x;};
    float get_y() {return obs_y;};

    SDL_Rect getCollision() const {return collision;};
    void render(SDL_Renderer* renderer);

private:
    float obs_x;
    float obs_y;

    float x_val = 0;

    SDL_Rect collision;

};

#endif // _OBSTACLE__H
