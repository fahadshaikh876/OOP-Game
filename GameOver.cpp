#include <SDL.h>
#include <iostream>
#include "GameOver.hpp"

void GameOver::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    srcRect = {2963, 1, 3508, 2480};
    Unit::draw(gRenderer, assets);
}

GameOver::GameOver()
{
    moverRect = {0, 0, 1200, 640};
}

SDL_Rect GameOver::posi()
{
    return moverRect;
}
GameOver::~GameOver()
{
}