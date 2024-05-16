#ifndef _MENU__H
#define _MENU__H

#pragma once

#include "define.h"
#include "graphics.h"
#include "texture.h"
#include "dino.h"
#include "obstacle.h"

#include <bits/stdc++.h>
using namespace std;

class Menu : Texture
{
public:
    Menu();
    ~Menu();
    int showMenu(SDL_Renderer* renderer);
    bool checkFocus(int x, int y);
    void renderMenu (SDL_Renderer* renderer);
    void close();
private:
    SDL_Surface* surface_menu;
    SDL_Texture* texture;

    int width_0, height_0;
    int width_1, height_1;
    int width_2, height_2;
    static const int menuItem = 3;
    Texture text_menu[menuItem];
    SDL_Rect item_pos[menuItem];

    bool menu0 = false; bool menu1=false; bool menu2=false;
    Texture menu;

    SDL_Texture* menu_texture;
    enum
    {
        PLAY = 1,
        EXIT = 2,
    };
};
#endif // _MENU__H
