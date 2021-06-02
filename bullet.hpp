#include <SDL.h>
#pragma once
#include<iostream>
#include "unit.hpp"
using namespace std;
/**
 * \brief bullet class is for another object of our game that is the bullet 
 * this is going to be generated via the gun (another class)
 * the bullets may hit the helicopter 
 */
class Bullet : public Unit{
    int mPosX, mPosY;
    int mVelX, mVelY;

public:
/**these are the attributes for the bullet 
 * the height, width and velocity 
 */
    int BULLET_WIDTH = 20;
    int BULLET_HEIGHT = 20;
    int BULLET_VEL = 1;

    void mover();
    int getmoverx();
    int getmovery();
    SDL_Rect posi();

    void draw(SDL_Renderer*, SDL_Texture* assets);
    Bullet(); 
    Bullet(int , int); 
    ~Bullet();
};