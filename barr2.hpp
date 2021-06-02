#include <SDL.h>
#include <iostream>
#include "unit.hpp"
#include <list>
#pragma once
using namespace std;
/**
 * \brief another barrier class since we have two barriers 
 * this is same as the first barrier class 
 */
class Bari2 : public Unit
{
    int countB = 0;
    int b;

public:

    void locat();
    void draw(SDL_Renderer *, SDL_Texture *assets);
    Bari2(int,int);
    Bari2();
    SDL_Rect posi();
    ~Bari2();
};
