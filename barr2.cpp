#include <SDL.h>
#include <iostream>
#include "barr2.hpp"

using namespace std;
/**
 * this class has the same functions as the first barrier class
 * however when you look into the functions, you will notice a change in coordinates
 */
void Bari2::locat()
{

    if (countB == 0)
    {
        b = 1180;
    }
    else if (countB == 1)
    {
        b = 1230;
        countB = -1;
    }
    if (moverRect.x < -50)
    {
        moverRect.x = 1200;
        moverRect.y = (rand() % 600);
    }

    countB++;
    moverRect.x -= 6;
}

SDL_Rect Bari2::posi()
{
    return moverRect;
}

void Bari2::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    locat();
    srcRect = {2851, 311, 108, 239};
    Unit::draw(gRenderer, assets);
}
Bari2::Bari2()
{
    moverRect = {600, 0, 50, 200};
}
Bari2::Bari2(int x, int y)
{
    moverRect = {x, y, 50, 160};
}

Bari2::~Bari2()
{
}