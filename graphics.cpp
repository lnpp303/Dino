
#include "graphics.h"
#include <bits/stdc++.h>
using namespace std;
bool Graphics::init () {
    bool success = true;
    if ((SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
            printf( "SDL init fail! Error: %s\n", SDL_GetError() );
            success = false;
    }
    int imgFlag = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlag ) & imgFlag ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        success=false;
    }

    if( TTF_Init() == -1 )
    {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
         success=false;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
         success=false;
    }
    else
    {
        if (SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            window = SDL_CreateWindow("HELLO SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
            if (window==NULL) {
                    printf( "SDL create window fail! Error: %s\n", SDL_GetError() );
                    success = false;
            }
            else
            {
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

    TTF_CloseFont(font);
	font = NULL;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer=NULL;
    window=NULL;

    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
    Mix_Quit();
}










