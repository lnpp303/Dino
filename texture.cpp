#include "texture.h"
#include <bits/stdc++.h>

using namespace std;

Texture::Texture() {
    texture=NULL;
    w_texture=0;
    h_texture=0;
}
Texture::~Texture() {
    free();
}
void Texture::free() {
    if (texture!=NULL) {
        SDL_DestroyTexture(texture);
        texture=NULL;
        w_texture=0;
        h_texture=0;
    }
}
bool Texture::loadFromFile(string path, SDL_Renderer* renderer) {
    //deallocate preexisting texture
    free();
    SDL_Texture* newTexture= NULL;

    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == NULL) {
        printf("Failed to load image. Error: %s\n", SDL_GetError());
    }
    else {
        SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xff, 0xff, 0xff));
        newTexture=SDL_CreateTextureFromSurface(renderer, surface);
        if (newTexture==NULL) {
            printf ("Failed to create texture. Erro: %s\n", SDL_GetError());

        }
        else {
                w_texture=surface->w;
                h_texture=surface->h;
        }
        SDL_FreeSurface(surface);
    }
    texture=newTexture;
    return texture!=NULL;

}
bool Texture::loadMedia(string path, SDL_Renderer* renderer) {

    if (!loadFromFile(path, renderer)) return false;
    return true;
}
void Texture::render (int x, int y, SDL_Renderer* renderer) {
    SDL_Rect renderQuad = {x, y, w_texture, h_texture};
    SDL_RenderCopy(renderer, texture, NULL , &renderQuad);
}
void Texture::renderClip(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip){
    SDL_Rect renderQuad = {x, y, w_texture, h_texture};
	if(clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopy(renderer, texture, clip, &renderQuad );
}
bool Texture::loadClip(string path, SDL_Renderer* renderer) {
    if (!loadFromFile(path, renderer)) return false;
    else {
        clip[0].x = 0; clip[0].y=0; clip[0].w=144; clip[0].h=144;
        clip[1].x = 144; clip[1].y=0; clip[1].w=144; clip[1].h=144;
        clip[2].x = 2*144; clip[2].y=0; clip[2].w=144; clip[2].h=144;
        clip[3].x = 3*144; clip[3].y=0; clip[3].w=144; clip[3].h=144;
        clip[4].x = 4*144; clip[4].y=0; clip[4].w=144; clip[4].h=144;

        clip[5].x = 5*144; clip[5].y=0; clip[5].w=144; clip[5].h=144;
        clip[6].x = 6*144; clip[6].y=0; clip[6].w=144; clip[6].h=144;
        clip[7].x = 7*144; clip[7].y=0; clip[7].w=144; clip[7].h=144;
        clip[8].x = 8*144; clip[8].y=0; clip[8].w=144; clip[8].h=144;
        clip[9].x = 9*144; clip[9].y=0; clip[9].w=144; clip[9].h=144;

        clip[10].x = 10*144; clip[10].y=0; clip[10].w=144; clip[10].h=144;
        clip[11].x = 11*144; clip[11].y=0; clip[11].w=144; clip[11].h=144;
        clip[12].x = 12*144; clip[12].y=0; clip[12].w=144; clip[12].h=144;
        clip[13].x = 13*144; clip[13].y=0; clip[13].w=144; clip[13].h=144;
        clip[14].x = 14*144; clip[14].y=0; clip[14].w=144; clip[14].h=144;
    }
    return true;
}









