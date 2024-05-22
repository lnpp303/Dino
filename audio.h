#ifndef _AUDIO__H
#define _AUDIO__H

#pragma once
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
class Audio
{
public:
    Audio();
    ~Audio();

    Mix_Music* loadMusic(const char* path);
    void play(Mix_Music* music);
    Mix_Chunk* loadSound(const char* path);
    void play(Mix_Chunk* chunk);
    void handleEvent(SDL_Event audio_e);

    bool isAudio = true;
};


#endif // _AUDIO__H

