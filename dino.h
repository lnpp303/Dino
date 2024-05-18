#ifndef DINO_H_
#define DINO_H_

#pragma once

#include "graphics.h"
#include "texture.h"
#include "obstacle.h"

using namespace std;

class Obs;

const float GRAVITY =0.5;
const float MAX_GRAVITY=20;
const int DINO_X = 330;
const int DINO_Y = 390;
const int RUN_FRAME = 15;
const int COUCH_FRAME = 7;
const int FRAME_SIZE = 108;

class Dino : Texture
{
public:
    Dino();
    ~Dino();
    bool loadFromFile(string path, SDL_Renderer* renderer);
    void handleInput(SDL_Event& e);
    void gravity();
    bool checkCollision(SDL_Rect a, SDL_Rect b);
    void update(vector <Obs*>& obsList);
    float getX() const {return dino_x;};
    float getY() const {return dino_y;};
    bool isDeath() const {return death;};
    void render(SDL_Renderer* renderer);

private:
    float dino_x = 0;
    float dino_y = 0;

    float y_val = 0;

    bool jump = false;
    bool couch = false;
    //bool fall = false;
    bool death = false;
    bool ground = true;

    SDL_Rect runClips[RUN_FRAME];
    SDL_Rect couchClips[COUCH_FRAME];

    SDL_Rect collision;
    int run_cnt = 0;
    int couch_cnt = 0;
};

#endif // DINO_H_
