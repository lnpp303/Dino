#include "texture.h"
#include <bits/stdc++.h>

using namespace std;

Texture::Texture() {
    texture=NULL;
    w_texture=0;
    h_texture=0;
}
Texture::~Texture() {

}

void Texture::free() {
    if (texture!=NULL) {
        SDL_DestroyTexture(texture);
        texture=NULL;
        w_texture=0;
        h_texture=0;
    }
}

//texture
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
//text
void Texture::setColor(int type)
{
    if (type == RED)
    {
        SDL_Color color = {255, 0, 0};
        text_color = color;
    }
    if (type == WHITE)
    {
        SDL_Color color = {255, 255, 255};
        text_color = color;
    }
    if (type == BLACK)
    {
        SDL_Color color = {0, 0, 0};
        text_color = color;
    }
}
bool Texture::loadText_S ( SDL_Renderer* renderer)
{
    font = TTF_OpenFont( "ChangaOne-Regular.ttf", 30 );
	if( font == NULL )
	{
		printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );

	}
	else
	{
	    //Render text
		free();
		//Render text surface
        SDL_Surface* textSurface = TTF_RenderText_Solid( font, str_val.c_str(), text_color );

        if( textSurface == NULL )
        {
            printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
        }
        else
        {
            //Create texture from surface pixels
            texture = SDL_CreateTextureFromSurface( renderer, textSurface );

            if( texture == NULL )
            {
                printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
            }
            else
            {
                //Get image dimensions
                w_texture = textSurface->w;
                h_texture = textSurface->h;


            }

                //Get rid of old surface
                SDL_FreeSurface( textSurface );
        }

	}
    return texture!=NULL;

}

bool Texture::loadText_L ( SDL_Renderer* renderer)
{
    font = TTF_OpenFont( "ChangaOne-Regular.ttf", 80 );
	if( font == NULL )
	{
		printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );

	}
	else
	{
	    //Render text
		free();
		//Render text surface
        SDL_Surface* textSurface = TTF_RenderText_Solid( font, str_val.c_str(), text_color );

        if( textSurface == NULL )
        {
            printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
        }
        else
        {
            //Create texture from surface pixels
            texture = SDL_CreateTextureFromSurface( renderer, textSurface );

            if( texture == NULL )
            {
                printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
            }
            else
            {
                //Get image dimensions
                w_texture = textSurface->w;
                h_texture = textSurface->h;
            }

                //Get rid of old surface
                SDL_FreeSurface( textSurface );
        }

	}
    return texture!=NULL;

}





