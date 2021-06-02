#include <SDL.h>
#include "unit.hpp"
#pragma once
//#include "bullet.hpp"
/** \brief the gun class is used for the machine gun that is another object of our game 
 * width, height and velocity are its attributes 
 * functions and constructors have been initialized here 
 */

class lifeTrack : public Unit
{
    int position = 0;
    int mPosX, mPosY;
    int mVelX, mVelY;

public:
    int LIFE_WIDTH = 20;
    int LIFE_HEIGHT = 20;
    void mover();
    void draw(SDL_Renderer *, SDL_Texture *assets);
    lifeTrack(int);
    ~lifeTrack();
};