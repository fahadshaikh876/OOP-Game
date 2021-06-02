#include "gun.hpp"
#include <iostream>

using namespace std;
/** this class consists of the draw function 
 * its constructor assigns and intializes value for its position 
 */
void Gun::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    srcRect = {1347, 360, 1350, 520};
    Unit::draw(gRenderer, assets);
}

Gun::Gun()
{
    mPosX = 4;
    mPosY = 4;
    mVelX = 0;
    mVelY = 0;

    moverRect = {0, 300, 100, 60};
}
/** the release function basically is used to that we can release bullets when we are at certain x and y values of moverrect 
 */

int Gun::getmoverx()
{
    return moverRect.x;
}

int Gun::getmovery()
{
    return moverRect.y;
}

/**mover function for the movement of the gun
 */

void Gun::mover()
{
    if (position == 1)
    {
        SDL_Delay(10);
        moverRect.y -= 1;
        if (moverRect.y < 0)
        {
            position = 0;
            moverRect.y = 0;
        }
    }

    else if (position == 0)
    {
        SDL_Delay(10);
        moverRect.y += 1;
        if (moverRect.y > 580)
        {
            position = 1;
            moverRect.y = 580;
        }
    }
}

Gun::~Gun()
{
}
