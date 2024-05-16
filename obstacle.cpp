#include "obstacle.h"

#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

Obs::Obs()
{
    int rand_x = 600 +rand()% (1042-600);
    cerr <<'_'<< rand_x <<'_'<<endl;
    if (rand_x < DINO_X  || rand_x >= SCREEN_WIDTH)
        {
            rand_x = 900;
        }
    obs_x = rand_x;
    obs_y = 390;
    collision = {obs_x, obs_y, 87, 91};
}
Obs::~Obs()
{

}
void Obs::handleMove()
{
    obs_x -= x_val ;// tốc độ di chuyển của obs

    if (obs_x <0)
    {
        int rand_x = 600+rand()% (1042-600);
        cerr <<'_'<< rand_x <<'_'<<endl;
        if (rand_x < DINO_X +200 || rand_x >= SCREEN_WIDTH)
        {
            rand_x = 900;
        }
        obs_x = rand_x;

    }


}

void Obs::render (SDL_Renderer* renderer)
{
    //handleMove();
    Texture::render(obs_x, obs_y, renderer);
}


bool Obs::loadFromFile (string path, SDL_Renderer* renderer)
{
    bool res = Texture::loadFromFile(path, renderer);
    return res;
}
