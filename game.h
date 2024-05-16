#ifndef _GAME__H
#define _GAME__H

#pragma once

#include "define.h"
#include "graphics.h"
#include "texture.h"
#include "dino.h"
#include "obstacle.h"

#include <bits/stdc++.h>
using namespace std;



class Game {
public:
    Game();
    ~Game();
    void drawMenu();
    bool menuLoop();
    bool menuLose();

private:
    Graphics graphics;
    Texture intro_text; Texture play_text; Texture rank_text;
    bool introduction; bool play; bool ranking;
    //SDL_Texture* menuText[3] = {introduction, play, ranking};
    int mouse_x; int mouse_y;

    bool mainMenu=true;
    bool Intro = true;
    bool Play = true;
    bool Rank = true;

};


#endif // _GAME__H
