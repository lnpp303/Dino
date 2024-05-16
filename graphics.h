#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include "define.h"
#include "texture.h"

using namespace std;
struct Graphics : Texture
{

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* texture = NULL;
    TTF_Font* font = NULL;

    bool init ();
    void close ();

};

#endif // _GRAPHICS__H
