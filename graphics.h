#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include "audio.h"
using namespace std;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 512;

class Graphics
{
public:

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* texture = NULL;
    TTF_Font* font = NULL;

    bool init ();
    void close ();

};

#endif // _GRAPHICS__H
