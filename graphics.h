#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include "define.h"

using namespace std;
struct Graphics {

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* texture = NULL;
    bool init ();
    void close ();
};

#endif // _GRAPHICS__H
