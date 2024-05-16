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

bool Texture::init(SDL_Renderer* renderer)
{
    bool success = true;
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF );

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        success = false;
    }

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    return success;
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
bool Texture::loadText1 ( SDL_Renderer* renderer)
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
void Texture::createText1 (int x, int y, SDL_Renderer* renderer)
{
    if (loadText1(renderer))
    {

        render(x, y, renderer);
    }
}

bool Texture::loadText2 ( SDL_Renderer* renderer)
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
void Texture::createText2 (int x, int y, SDL_Renderer* renderer)
{
    if (loadText2(renderer))
    {

        render(x, y, renderer);
    }
}





