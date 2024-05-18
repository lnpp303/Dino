
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>

#include <bits/stdc++.h>
#include "graphics.h"
#include "texture.h"
#include "dino.h"
#include "obstacle.h"

using namespace std;

enum TextColor
    {
        RED = 0,
        BLACK = 1,
        WHITE = 2,
    };
int main (int argc, char* argv[]) {
    Graphics graphics;
    Texture background;

    Dino player;

    int scolingOffset=0;
    bool isRunning=true; SDL_Event e;
    bool isMenu=true;

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

    int menuItem = 3;
    Texture menu_back;
    Texture menu_text[menuItem];
    Texture menu_button[menuItem];
    SDL_Rect button_pos[menuItem];
    SDL_Rect text_pos[menuItem];

    menu_text[0].setText("Play"); menu_text[0].setColor(BLACK);
    button_pos[0].x=400; button_pos[0].y=280; button_pos[0].w=196; button_pos[0].h=84;
    text_pos[0].x=470; text_pos[0].y=300; text_pos[0].w=196; text_pos[0].h=84;

    menu_text[1].setText("Quit"); menu_text[1].setColor(BLACK);
    button_pos[1].x=400; button_pos[1].y=370; button_pos[1].w=196; button_pos[1].h=84;
    text_pos[1].x=470; text_pos[1].y=390; text_pos[1].w=196; text_pos[1].h=84;

    menu_text[2].setText("DINASOUR"); menu_text[2].setColor(BLACK);
    text_pos[2].x=320; text_pos[2].y=160; text_pos[2].w=196; text_pos[2].h=84;

    if (!menu_back.loadFromFile("menu.png", graphics.renderer)
        || !menu_button[0].loadFromFile("button.png", graphics.renderer)|| !menu_button[1].loadFromFile("button.png", graphics.renderer)
        ||!menu_text[0].loadText_S( graphics.renderer) || !menu_text[1].loadText_S( graphics.renderer)||!menu_text[2].loadText_L( graphics.renderer))
    {
        std::cout << "LOAD MENU ERROR" << std::endl;
        return -1;
    }

    int m_x=0; int m_y=0;


    vector <Obs*> obsList;
    for (int i=0; i<5; i++)
    {
        int min_distance = DINO_X+200;
        if (i!=0) min_distance = obsList.at(i-1)->getX() + 600;
        int rand_x = min_distance +rand()% (600);

        Obs* cactus = new Obs (rand_x, 390);
        cerr<< cactus->getX()<<endl;
        if (!cactus->loadFromFile("Cactus.png", graphics.renderer))
        {
            printf("Load error %s\n", SDL_GetError());

        }
        obsList.push_back(cactus);
    }

    while (isMenu)
    {
        while (SDL_PollEvent(&e)!=0)
        {
            if (e.type == SDL_QUIT)
            {
                isMenu = false;
            }
        SDL_RenderClear(graphics.renderer);
        menu_back.render(0, 0, graphics.renderer);
        menu_button[0].render(button_pos[0].x, button_pos[0].y, graphics.renderer);
        menu_button[1].render(button_pos[1].x, button_pos[1].y, graphics.renderer);

        for (int i=0; i<menuItem; i++)
        {
            menu_text[i].render(text_pos[i].x, text_pos[i].y, graphics.renderer);
        }

        switch (e.type)
        {
            case SDL_MOUSEMOTION:
            {
                m_x = e.motion.x;
                m_y = e.motion.y;
                for (int i=0; i<2; i++)
                {
                    if (m_x>button_pos[i].x && m_x<button_pos[i].x+button_pos[i].w
                    && m_y>button_pos[i].y && m_y<button_pos[i].y+button_pos[i].h)
                    {
                        menu_text[i].setColor(RED);

                        if (!menu_text[i].loadText_S( graphics.renderer))
                        {
                            return -1;
                        }
                        menu_text[i].render(text_pos[i].x, text_pos[i].y, graphics.renderer);

                    }
                    else
                    {
                        menu_text[i].setColor(BLACK);

                        if (!menu_text[i].loadText_S( graphics.renderer))
                        {
                            return -1;
                        }
                        menu_text[i].render(text_pos[i].x, text_pos[i].y, graphics.renderer);
                    }
                }
            }
            case SDL_MOUSEBUTTONDOWN:
                {
                    m_x=e.button.x;
                    m_y= e.button.y;
                    if(m_x>button_pos[0].x+30 && m_x<button_pos[0].x+button_pos[0].w-30
                    && m_y>button_pos[0].y+10 && m_y<button_pos[0].y+button_pos[0].h-10)
                    {
                        if (e.button.button==SDL_BUTTON_LEFT)
                        {
                            isRunning=true;
                            isMenu=false;
                        }
                    }
                    else if (m_x>button_pos[1].x+30 && m_x<button_pos[1].x+button_pos[1].w-30
                            && m_y>button_pos[1].y+10 && m_y<button_pos[1].y+button_pos[1].h-10)
                            {
                                if (e.button.button==SDL_BUTTON_LEFT)
                                {
                                    isMenu=false;
                                }
                            }
                }
        }

        SDL_RenderPresent(graphics.renderer);

        }
    }

    while (isRunning)
    {
        while (SDL_PollEvent(&e)!=0)
        {
            if (e.type == SDL_QUIT)
            {
                isRunning = false;
            }

            player.handleInput(e);

        }

        SDL_RenderClear(graphics.renderer);
        int frame_start = SDL_GetTicks();

        scolingOffset-= 15; // tăng tốc back
        if (scolingOffset < -background.getWidth())
        {
            scolingOffset = 0;
        }
        background.render(scolingOffset,0, graphics.renderer);
        background.render(scolingOffset+background.getWidth(),0, graphics.renderer);

        for (int i=0; i<5; i++)
        {
            if (obsList.at(i) != NULL)
            {
                if (obsList.at(i)->getX() >0)
                {
                    obsList.at(i)->render(graphics.renderer, -8);
                }
                else
                {
                    delete obsList.at(i);
                    obsList.at(i) = NULL;
                    obsList.erase(obsList.begin()+i);
                    int rand_x = obsList.at(3)->getX() + 600 + rand()% (600);

                    Obs* cactus = new Obs (rand_x, 390);
                    if (!cactus->loadFromFile("Cactus.png", graphics.renderer))
                    {
                        printf("Load error %s\n", SDL_GetError());

                    }
                    cerr<<cactus->getX() << endl;
                    obsList.push_back(cactus);
                }
            }
        }
        player.update(obsList);
        player.render(graphics.renderer);

        if (player.isDeath())
        {
            isMenu = true;
            isRunning = false;

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
    menu_back.free();
    for (int i=0; i<menuItem; i++)
    {
        menu_button[i].free();
        menu_text[i].free();
    }
    return 0;
}

