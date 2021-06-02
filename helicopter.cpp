#include "helicopter.hpp"
#include <iostream>
/** helicopter implementation will go here.
 * it has the flying function that allows the helicopter to be floating in the sky background 
 * the vector allows positioning
 */
using namespace std;
void Helicopter::helifly()
{
    if (counth == 0)
    {
        h = 835;
    }
    else if (counth == 1)
    {
        h = 985;
    }
    else if (counth == 2)
    {
        h = 1135;
    }
    else if (counth == 3)
    {
        h = 1285;
        counth = -1;
    }

    counth++;

    srcRect = {868, h, 380, 131};
    moverRect.x += 2;
}
Helicopter::~Helicopter()
{
}

void Helicopter::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{

    Helicopter::helifly();

    Unit::draw(gRenderer, assets);
}

Helicopter::Helicopter()
{
    mPosX = 0;
    mPosY = 0;
    mVelX = 0;
    mVelY = 0;

    moverRect = {25, 40, 125, 60};
}
/** handle events function is handling the movement of the helicopter 
 * in such a way that the pressing of the keys on the keyboard would determine its movement
 * it can be up, down, left and right depending on what key is pressed 
 * the terminal would also be giving an output of the pressed key
 * for example it will output uppp in case the up arrow is pressed on the keyboard 
 */

void Helicopter::handleEvent(SDL_Event &e)
{
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            up = true;
            cout << "uppppp" << endl;
            break;
        case SDLK_DOWN:
            down = true;
            cout << "down" << endl;

            break;
        case SDLK_LEFT:
            cout << "left" << endl;
            left = true;
            break;
        case SDLK_RIGHT:
            right = true;
            cout << "right" << endl;
            break;
        }
    }
    else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            up = false;
            break;
        case SDLK_DOWN:
            down = false;
            break;
        case SDLK_LEFT:
            left = false;

            break;
        case SDLK_RIGHT:
            right = false;
            break;
        }
    }
    if (right)
    {
        moverRect.x += 15;
    }
    if (left)
    {
        moverRect.x -= 15;
    }

    if (up)
    {
        moverRect.y -= 15;
    }
    if (down)
    {
        moverRect.y += 15;
    }
}

void Helicopter::collision()
{
    if (moverRect.y < 321)
    {
        moverRect.x += 5;
        moverRect.y -= 30;
    }
    else if (moverRect.y > 320)
    {
        moverRect.x += 5;
        moverRect.y += 30;
    }
}

SDL_Rect &Helicopter::posi()
{
    return moverRect;
}
/** the move funtion is for the movement for the helicopter which is clear by its name 
 * Move the dot left or right by mPosX += mVelX;
 * there ae conditions to tackle situations if the helicopter went too far up or down 
 */

SDL_Rect &Helicopter::pixels()
{
    return srcRect;
}

void Helicopter::move()
{

    if (moverRect.x <= 0)
    {
        moverRect.x = 0;
    }

    if (moverRect.x >= 1075)
    {
        moverRect.x = 1075;
    }

    if (moverRect.y < 0)
    {
        moverRect.y = 0;
    }

    if (moverRect.y > 580)
    {
        moverRect.y = 580;
    }
}
