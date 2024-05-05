#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "define.h"
#include "graphics.h"
#include "texture.h"

using namespace std;

void waitUntilKeyPress () {
    SDL_Event e; bool quit = false;
        while (quit==false) {
            while ( SDL_PollEvent(&e) ) {
                if (e.type == SDL_QUIT) quit=true;
            }
        }
}
int main (int argc, char* argv[]) {
    Graphics graphics;
    Texture background;
    Texture character;

    if (!graphics.init()) printf ("Failed to intialize!");
    else {
        SDL_RenderClear(graphics.renderer);
        SDL_SetRenderDrawColor( graphics.renderer, 0xff, 0xff, 0xff, 0xff );
        if (background.loadMedia("background.png", graphics.renderer)) {
            background.render(0,0, graphics.renderer);
        }

        if (character.loadClip("Dino.png", graphics.renderer)){
            for (int i=0; i<24; i++) {
                character.renderClip(350, 370, graphics.renderer,&character.clip[i] );

            }
        }
    //Render finished texture to front screen
        SDL_RenderPresent(graphics.renderer);
        waitUntilKeyPress();
    }
    graphics.close();
    return 0;
}
