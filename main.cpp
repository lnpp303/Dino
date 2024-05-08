#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "define.h"
#include "graphics.h"
#include "texture.h"
#include "scolling.h"

using namespace std;

void waitUntilKeyPress () {
    SDL_Event e;
        while (true) {
        while ( SDL_PollEvent(&e)!=0 ) {
                switch (e.type ){
                    case SDL_QUIT: exit(0);
                    break;
                }
            }
        }
}
int main (int argc, char* argv[]) {
    Graphics graphics;

    Texture background;
    Texture character;

    int scolingOffset=0;
    bool isRunning=true; SDL_Event e;
    if (!graphics.init()) printf ("Failed to intialize!");
    else {
        if (background.loadMedia("background.png", graphics.renderer))
            {
            if (character.loadClip("Dino.png", graphics.renderer)){


                     while (isRunning)
                    {

                        while(SDL_PollEvent(&e)!=0)
                        {
                            if (e.type == SDL_QUIT)
                            {
                                isRunning = false;
                            }
                        }
                        --scolingOffset;
                        if (scolingOffset < -background.getWidth())
                        {
                            scolingOffset = 0;
                        }
                        background.render(scolingOffset,0, graphics.renderer);
                        background.render(scolingOffset+background.getWidth(),0, graphics.renderer);
                    for (int i=0; i<15; i++) {
                    SDL_RenderClear(graphics.renderer);
                    character.renderClip(350, 370, graphics.renderer,&character.clip[i] );
                    SDL_RenderPresent(graphics.renderer);
                    SDL_Delay(5);
                    if (i==14) i=0;
                    }
                }

            }
        }
    }

   /* bool isRunning = true;
    SDL_Event e;
    if (!graphics.init())
    {
        printf ("Failed to intialize!");
        return -1;
    }
    if (!background.loadMedia("background.png", graphics.renderer))
    {
        return -1;
    }
    if (!character.loadClip("Dino.png", graphics.renderer))
        {
            return -1;
        }

            for (int i=0; i<15; i++)
            {
            SDL_RenderClear(graphics.renderer);
            character.renderClip(350, 370, graphics.renderer,&character.clip[i] );
            if (i==14) i=0;
    while (isRunning)
    {
        while(SDL_PollEvent(&e)!=0)
        {
            if (e.type == SDL_QUIT)
            {
                isRunning = false;
            }
        }



            --scolingOffset;
            if (scolingOffset < -background.getWidth())
            {
                scolingOffset = 0;
            }

        background.render(scolingOffset,0, graphics.renderer);
        background.render(scolingOffset+background.getWidth(),0, graphics.renderer);

        SDL_RenderPresent(graphics.renderer);

        SDL_Delay(5);
        }
    }
*/
    //waitUntilKeyPress();
    graphics.close();
    background.free();
    return 0;
}
