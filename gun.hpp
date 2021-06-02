#include <SDL.h>
#include "bullet.hpp"
#include "unit.hpp"
#pragma once
/** \brief the gun class is used for the machine gun that is another object of our game 
 * width, height and velocity are its attributes 
 * functions and constructors have been initialized here 
 */
class Gun : public Unit{
    int position = 0;
    int mPosX, mPosY;
    int mVelX, mVelY;

public:
    int GUN_WIDTH = 20;
    int GUN_HEIGHT = 20;
    int GUN_VEL = 1;

    void mover();
    int getmoverx();
    int getmovery();

    void draw(SDL_Renderer*, SDL_Texture* assets);
    Gun(); 
    ~Gun();
    
};