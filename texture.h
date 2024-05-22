#ifndef _TEXTURE__H
#define _TEXTURE__H

#pragma once
#include <SDL_ttf.h>
#include <bits/stdc++.h>

#include "graphics.h"

using namespace std;


class Texture {
public:

    Texture();
    ~Texture();
    //dellocate texture
    void free();
    virtual bool loadFromFile(string path, SDL_Renderer* renderer);

    void render (int x, int y, SDL_Renderer* renderer);
    int getWidth() {return w_texture;}
    int getHeight() {return h_texture;}
    void renderClip(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip);

    bool loadText_S ( SDL_Renderer* renderer);
    bool loadText_L ( SDL_Renderer* renderer);

    void setText(string text) {str_val=text;};
    void setColor(int type);

private:
    SDL_Texture* texture;

    SDL_Rect clip[15];

    int w_texture;
    int h_texture;



    TTF_Font* font;

    string str_val;
    SDL_Color text_color;

enum TextColor
    {
        RED = 0,
        BLACK = 1,
        WHITE = 2,
    };

};

#endif // _TEXTURE__H
