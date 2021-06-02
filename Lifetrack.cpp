#include "lifetrack.hpp"
#include <iostream>

using namespace std;

/** this class consists of the draw function 
 * its constructor assigns and intializes value for its position 
 */

void lifeTrack::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    srcRect = {800, 0, 300, 200};
    Unit::draw(gRenderer, assets);
}

lifeTrack::~lifeTrack()
{
}
lifeTrack::lifeTrack(int x)
{
    mPosX = 0;
    mPosY = 0;
    mVelX = 0;
    mVelY = 0;

    if (x == 1)
    {
        moverRect = {0, 0, 100, 60};
    }
    else if (x == 2)
    {
        moverRect = {50, 0, 100, 60};
    }
    else if (x == 3)
    {
        moverRect = {100, 0, 100, 60};
    }
    else if (x == 4)
    {
        moverRect = {150, 0, 100, 60};
    }
    else if (x == 5)
    {
        moverRect = {200, 0, 100, 60};
    }
}
/** the release function basically is used to that we can release bullets when we are at certain x and y values of moverrect 
 */

/**mover function for the movement of the gun
 */
