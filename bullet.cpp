#include "bullet.hpp"
#include <iostream>

using namespace std;

void Bullet::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
	srcRect = {0, 0, 800, 309};
	Unit::draw(gRenderer, assets);
	moverRect.x += 7;
}

Bullet::Bullet()
{
	mPosX = 4;
	mPosY = 4;
	mVelX = 0;
	mVelY = 0;
	moverRect = {80, 320, 40, 24};
}

int Bullet::getmoverx()
{
	return moverRect.x;
}

SDL_Rect Bullet::posi()
{
	return moverRect;
}

int Bullet::getmovery()
{
	return moverRect.y;
}

/** bullet constructor is used in order to intitalize the offsets and intializing the velocity 
 */
Bullet::Bullet(int x, int y)
{
	mPosX = 4;
	mPosY = 4;
	mVelX = 0;
	mVelY = 0;
	moverRect = {x + 80, y + 20, 40, 24};
}
/**our bullet moves in the x direction hence defined by the mover function 
 */
void Bullet::mover()
{
	moverRect.x += 1;
}
Bullet::~Bullet()
{
}
