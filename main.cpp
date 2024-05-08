#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "define.h"
#include "graphics.h"
#include "texture.h"

using namespace std;

int main (int argc, char* argv[]) {
    Graphics graphics;

    Texture background;
    Texture character;

    int scolingOffset=0;
    bool isRunning=true; SDL_Event e;

    if (!graphics.init()) printf ("Failed to intialize!");
    else {
            while (isRunning)
            {
                if (background.loadMedia("background.png", graphics.renderer))
                {
                    if (character.loadClip("Dino.png", graphics.renderer))
                    {
                        while(SDL_PollEvent(&e)!=0)
                        {
                            if (e.type == SDL_QUIT)
                            {
                                isRunning = false;
                            }
                        }
                        for (int i=0; i<15; i++)
                        {
                            SDL_RenderClear(graphics.renderer);

                            --scolingOffset;
                            if (scolingOffset < -background.getWidth())
                            {
                                scolingOffset = 0;
                            }
                            background.render(scolingOffset,0, graphics.renderer);
                            background.render(scolingOffset+background.getWidth(),0, graphics.renderer);

                            character.renderClip(350, 370, graphics.renderer,&character.clip[i] );

                            SDL_RenderPresent(graphics.renderer);

                            SDL_Delay(57);
                            if (i==14) i=0;
                        }
                    }

                }
            }
        }

    graphics.close();
    background.free();
    return 0;
}
