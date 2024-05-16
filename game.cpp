#include "game.h"

#include <bits/stdc++.h>
using namespace std;
/*
Game::Game ()
{
    mouse_x = 0;
    mouse_y = 0;
cerr<<0;
    introduction = intro_text.loadText("Introduction", graphics.renderer );
cerr<<1;
    play = play_text.loadText("Play", graphics.renderer );
    cerr<<2;
    ranking = rank_text.loadText("Ranking", graphics.renderer );
}

Game::~Game()
{

}


void Game::drawMenu()
{
    if (mainMenu)
    {
        intro_text.render(300, 300, graphics.renderer);
        play_text.render(300, 350, graphics.renderer);
        rank_text.render(300, 400, graphics.renderer);
    }

    if (introduction)
    {
        intro_text.render(300, 300, graphics.renderer);
    }
    if (play)
    {
        play_text.render(300, 350, graphics.renderer);
    }
    if (ranking)
    {
        rank_text.render(300, 400, graphics.renderer);
    }

}

bool Game::menuLoop()
{
    SDL_GetMouseState(&mouse_x, &mouse_y);

    if (introduction==true)
    {
        if (mouse_x<250 && mouse_x > 350 && mouse_y<350 && mouse_y>400)
        {
            return mainMenu;

        }
        else return introduction=false;
    }
    if (play)
    {
        if (mouse_x<250 && mouse_x > 350 && mouse_y<400 && mouse_y>430)
        {

           return  mainMenu;
        }
        else return play=false;
    }
    if (ranking)
    {
        if (mouse_x<250 && mouse_x > 350 && mouse_y<430 && mouse_y>470)
        {

            return mainMenu;
        }
        else return ranking=false;
    }
}
*/
