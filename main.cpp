
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>

#include <bits/stdc++.h>
#include "define.h"
#include "graphics.h"
#include "texture.h"
#include "dino.h"
#include "obstacle.h"
//#include "menu.h"
using namespace std;

int main (int argc, char* argv[]) {
    Graphics graphics;
    Texture background;
    Texture obstacle;

    Dino player;

    Texture text;

    //Menu menu;
    int scolingOffset=0;


    bool isRunning=true; SDL_Event e;
    bool isMenu = true;

    if (!graphics.init())
    {
        printf ("Failed to intialize!");
        return -1;
    }

     if( TTF_Init() == -1 )
    {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
        return -1;
    }
    if (!player.loadFromFile("Dino.png", graphics.renderer) || !background.loadFromFile("background.png", graphics.renderer))
    {
        std::cout << "LOAD MEDIA ERROR" << std::endl;
        return -1;
    }

    while (isRunning)
    {

        while (SDL_PollEvent(&e)!=0)
        {
            if (e.type == SDL_QUIT)
            {
                isRunning = false;
            }

            player.HandleInput(e);
        }
        //menu.renderMenu(graphics.renderer);
       // menu.showMenu(graphics.renderer);

        int frame_start = SDL_GetTicks();
        SDL_RenderClear(graphics.renderer);

        scolingOffset-= 15; // tăng tốc back
        if (scolingOffset < -background.getWidth())
        {
            scolingOffset = 0;
        }
        background.render(scolingOffset,0, graphics.renderer);
        background.render(scolingOffset+background.getWidth(),0, graphics.renderer);

        player.Render(graphics.renderer);
        //srand(time(0));

        Obs* cactus = new Obs();  // hàm sinh random cactus ở đây
        if (!cactus->loadFromFile("Cactus.png", graphics.renderer))
        {
            cout << "LOAD OBS ERROR" << std::endl;
            return -1;
        }
        cactus->handleMove();
        cerr << cactus->get_x() <<endl;
        cactus->render(graphics.renderer);


        player.Update(cactus);

        if (player.isDeath())
        {
            isRunning = false; //hiện menu exit
        }


        SDL_RenderPresent(graphics.renderer);
        int frame_end = SDL_GetTicks();
        int real_time = frame_end-frame_start;
        int fps = 1000 / 30; // Muốn tăng tốc game thì tăng cái mẫu Thường cái này cố định
        if (fps > real_time)
        {
            SDL_Delay(fps-real_time);
        }


    }

    graphics.close();
    background.free();
   // menu.close();

    return 0;
}

