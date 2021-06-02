#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "field.hpp"
#pragma once

#include <list>

using namespace std;
/** \brief this is the basic game class which sets up everything for our game 
 */
class Game
{
    const int SCREEN_WIDTH = 1200;
    const int SCREEN_HEIGHT = 640;
    SDL_Window *gWindow = NULL;
    SDL_Renderer *gRenderer = NULL;
    SDL_Texture *gTexture = NULL;
    SDL_Texture *assets = NULL;
    Mix_Music *bgMusic = NULL;
    Mix_Chunk *CrashMusic = NULL;
    Mix_Chunk *BulletMusic = NULL;
    Mix_Chunk *LifeSound = NULL;
    int m_width;
    int m_height;
    Helicopter *dot = new Helicopter();
    Gun *gunbarrel = new Gun();

    SDL_Event e;

    int scrollingOffset = 0;
    bool intersected = false;
    bool interscBarier = false;
    int Crasher = 0;
    int Crashloop = 0;
    bool check = false;
    bool quit = true;

    SDL_Rect boomRect;
    SDL_Rect BoommoverRect;
    SDL_Rect gameOverRect;
    SDL_Rect gameOvermoverRect;

public:

    bool init();
    bool loadMedia();
    void close();
    SDL_Texture *loadTexture(std::string path);
    void run();
};
