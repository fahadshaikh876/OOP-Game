#include <SDL.h>
#include "unit.hpp"
#include <iostream>
#include "boom.hpp"

void Boom::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    srcRect = {1, 1837, 1024, 1024};
    Unit::draw(gRenderer, assets);
}

Boom::Boom(int x, int y)
{
    moverRect = {x, y - 175 / 2, 175, 175};
}

SDL_Rect Boom::posi()
{
    return moverRect;
}
Boom::~Boom()
{
}