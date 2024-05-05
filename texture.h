#ifndef _TEXTURE__H
#define _TEXTURE__H

#include <bits/stdc++.h>
#include "define.h"
#include "graphics.h"

using namespace std;

struct Texture {
public:

    Texture();
    //dellocate memory
    ~Texture();
    //dellocate texture
    void free();
    bool loadFromFile(string path, SDL_Renderer* renderer);
    bool loadMedia(string path, SDL_Renderer* renderer);
    //render texture at a given point
    void render (int x, int y, SDL_Renderer* renderer);
    int getWidth() {return w_texture;}
    int getHeight() {return h_texture;}

    void renderClip(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip);
    bool loadClip(string path, SDL_Renderer*renderer);
    SDL_Rect clip[15];

private:
    SDL_Texture* texture;

    int w_texture;
    int h_texture;


};

#endif // _TEXTURE__H
