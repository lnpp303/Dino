#include "obstacle.h"

#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

Obs::Obs(int x, int y)
{
    obs_x = x;
    obs_y = 390;
    collision = {obs_x, obs_y, 87, 91};
}
Obs::~Obs()
{

}
void Obs::render (SDL_Renderer* renderer, int camera_x)
{
    obs_x += camera_x;
    collision.x = obs_x;
    Texture::render(obs_x, obs_y, renderer);
}


bool Obs::loadFromFile (string path, SDL_Renderer* renderer)
{
    bool res = Texture::loadFromFile(path, renderer);
    return res;
}
