#include "menu.h"

#include <bits/stdc++.h>
using namespace std;


/*Menu::Menu()
{
    item_pos[2].x=320;
    item_pos[2].y=160;
    item_pos[0].x=470;
    item_pos[0].y=300;
    item_pos[1].x=470;
    item_pos[1].y=390;

}
Menu::~Menu ()
{

}

void Menu::renderMenu (SDL_Renderer* renderer)
{
    menu_texture = IMG_LoadTexture(renderer, "menu.png");
    SDL_RenderCopy( renderer, menu_texture, NULL, NULL);

    Texture button0;
    button0.loadFromFile("button.png", renderer);
    button0.render(400, 280, renderer);

    Texture button1;
    button1.loadFromFile("button.png", renderer);
    button1.render(400, 370, renderer);

    /*Texture button2;
    button2.loadFromFile("button.png", renderer);
    button2.render(400, 180, renderer);

    text_menu[0].setText("Play");
    text_menu[0].setColor(BLACK);
    width_0 = button0.getWidth();
    height_0 = button0.getHeight();

    text_menu[1].setText("Quit");
    text_menu[1].setColor(BLACK);
    width_1 = button1.getWidth();
    height_1 = button1.getHeight();

    text_menu[2].setText("DINASOUR");
    text_menu[2].setColor(WHITE);
    width_2 = item_pos[2].w;
    height_2 = item_pos[2].h;
}
void Menu::close()
{
    SDL_DestroyTexture(menu_texture);
    menu_texture=NULL;
}
bool Menu::checkFocus(int x, int y)
{
    if (x>=item_pos[0].x && x<=item_pos[0].x+width_0 && y>=item_pos[0].y && y<=item_pos[0].y+height_0)
    {
        menu0=true;
        menu1=false;
        menu2=false;
        return menu0;
    }
    else if (x>=item_pos[1].x && x<=item_pos[1].x+width_1 && y>=item_pos[1].y && y<=item_pos[1].y+height_1)
    {
        menu0=false;
        menu1=true;
        menu2=false;
        return menu1;
    }
    if (x>=item_pos[2].x && x<=item_pos[2].x+width_2 && y>=item_pos[2].y && y<=item_pos[2].y+height_2)
    {
        menu0=false;
        menu1=false;
        menu2=true;
        return menu2;
    }
    else return false;

}


int Menu::showMenu(SDL_Renderer* renderer)
{
    if(!Texture::loadFromFile("menu.png", renderer))
    {
        return -1;
    }

    bool selected[menuItem] = {0, 0 , 0};

    SDL_Event m_event; int m_x=0; int m_y=0;

    while (true)
    {

        text_menu[0].createText1(item_pos[0].x, item_pos[0].y, renderer);
        text_menu[1].createText1(item_pos[1].x, item_pos[1].y, renderer);
        text_menu[2].createText2(item_pos[2].x, item_pos[2].y, renderer);

        while (SDL_PollEvent(&m_event))
        {
            switch(m_event.type)
            {
                case SDL_QUIT: return -1;
                case SDL_MOUSEMOTION:
                    {
                        m_x = m_event.motion.x;
                        m_y = m_event.motion.y;
                        for (int i=0; i<menuItem; i++)
                        {
                            if (checkFocus(m_x, m_y))
                            {
                                if (selected[i]==false)
                                {
                                    selected[i]=1;
                                    text_menu[i].setColor(BLACK);
                                }
                            }
                            else
                            {
                              if (selected[i]==true)
                                {
                                    selected[i]=0;
                                    text_menu[i].setColor(RED);
                                }
                            }
                        }
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    {
                        m_x = m_event.button.x;
                        m_y = m_event.button.y;
                        for (int i=0; i<menuItem; i++)
                        {
                            if (checkFocus(m_x, m_y ))
                            {
                                return i;
                            }
                        }
                    }
                    break;
                case SDL_KEYDOWN:
                    {
                        if(m_event.key.keysym.sym==SDLK_BACKSPACE) return -1;
                    }
                    break;
            }
        }
    SDL_RenderPresent(renderer);
    }

}
*/
