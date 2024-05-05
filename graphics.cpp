#include "define.h"
#include "graphics.h"
#include <bits/stdc++.h>
using namespace std;
bool Graphics::init () {
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO)<0) {
            printf( "SDL init fail! Error: %s\n", SDL_GetError() );
            success = false;
    }
    else {
        if (SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            window = SDL_CreateWindow("HELLO SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
            if (window==NULL) {
                    printf( "SDL create window fail! Error: %s\n", SDL_GetError() );
                    success = false;
            }
            else {
                renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
                SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
            }
        }
    }
    return success;
}

void Graphics::close () {
    SDL_DestroyTexture(texture);
    texture = NULL;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer=NULL;
    window=NULL;

    IMG_Quit();
    SDL_Quit();
}










