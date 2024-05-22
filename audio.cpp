#include "audio.h"

Audio::Audio ()
{

}
Audio::~Audio()
{

}

Mix_Music* Audio::loadMusic(const char* path)
    {
        Mix_Music *music = Mix_LoadMUS(path);
        if (music == NULL) {
            printf( "Failed to load music! SDL_mixer Error: %s\n", Mix_GetError() );
        }
        return music;
    }
void Audio::play(Mix_Music *music)
{
    if (music == NULL) return;

    if (Mix_PlayingMusic() == 0)
    {
        Mix_PlayMusic( music, -1 );
    }
    else if( Mix_PausedMusic() == 1 )
    {
        Mix_ResumeMusic();
    }
}

Mix_Chunk* Audio::loadSound(const char* path)
{
    Mix_Chunk* chunk = Mix_LoadWAV(path);
    if (chunk == NULL)
    {
        printf( "Failed to load chunk! SDL_mixer Error: %s\n", Mix_GetError() );

    }
}
void Audio::play(Mix_Chunk* chunk)
{
    if (chunk != NULL)
    {
        Mix_PlayChannel( -1, chunk, 0 );
    }
}

/*void Audio::handleEvent(SDL_Event audio_e)
{
    while( SDL_PollEvent( &audio_e ) != 0 )
    {
        if( audio_e.type == SDL_QUIT )
        {
            isAudio = false;
        }

        else if( audio_e.type == SDL_KEYDOWN )
        {
            switch( audio_e.key.keysym.sym )
            {

                case SDLK_SPACE:
                     if( Mix_PausedMusic() == 1 )
                        {
                            Mix_ResumeMusic();
                        }
                        else
                        {
                            Mix_PauseMusic();
                        }

                    break;

                    case SDLK_F1:
                        Mix_HaltMusic();
                        break;
            }
        }
    }
}*/

