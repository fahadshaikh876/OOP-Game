#include <SDL.h>
#include "unit.hpp"
#pragma once

/** \brief this is for the implementation of the helicopter object
 */
class Helicopter : public Unit
{
protected:
    /** the attributes include integer values to handle the helicopter's position 
 * the boolean type attributes are there in order to work with the keyboard inputs that would allow the helicopter to move left, right, up or down 
 */
private:
    int counth = 0;
    int h;
    int mPosX, mPosY;
    int mVelX, mVelY;
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
    /**the attributes also involve the height, width of the helicopter 
 */
public:

    int DOT_WIDTH;
    int DOT_HEIGHT;

    int DOT_VEL = 10;
    void handleEvent(SDL_Event &e);
    void move();
    void collision();

    void helifly();

    void draw(SDL_Renderer *, SDL_Texture *assets);
    Helicopter();
    SDL_Rect &pixels();
    SDL_Rect &posi();
    ~Helicopter();
};
