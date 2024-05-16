#ifndef _TEXTURE__H
#define _TEXTURE__H

#pragma once
#include <SDL_ttf.h>
#include <bits/stdc++.h>
#include "define.h"
//#include "graphics.h"

using namespace std;


class Texture {
public:

    Texture();
    //dellocate memory
    ~Texture();
    //dellocate texture
    void free();
    bool init(SDL_Renderer* renderer);
    virtual bool loadFromFile(string path, SDL_Renderer* renderer);

    //render texture at a given point
    void render (int x, int y, SDL_Renderer* renderer);
    int getWidth() {return w_texture;}
    int getHeight() {return h_texture;}
    void renderClip(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip);

    bool loadText1 ( SDL_Renderer* renderer);
    bool loadText2 ( SDL_Renderer* renderer);
    //bool loadFromRenderedText (SDL_Renderer* renderer);

    void setText(string text) {str_val=text;};
    void setColor(int type);
    void createText1 (int x, int y, SDL_Renderer* renderer);
    void createText2 (int x, int y, SDL_Renderer* renderer);


    enum TextColor
    {
        RED = 0,
        BLACK = 1,
        WHITE = 2,
    };

private:
    SDL_Texture* texture;

    SDL_Rect clip[15];

    int w_texture;
    int h_texture;



    TTF_Font* font;

    string str_val;
    SDL_Color text_color;

};

#endif // _TEXTURE__H
