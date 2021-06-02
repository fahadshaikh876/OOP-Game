#include <SDL.h>
#include <iostream>
#include <vector>
#include "unit.hpp"
#pragma once
using namespace std;
/** \brief this class is handling the brown barriers in our game 
*/
/**
* this is the hpp file so we are just intializing functions and constructors 
*/
class Bari : public Unit
{
    int countB = 0;
    int b;

public:
    void locat();

    void draw(SDL_Renderer *, SDL_Texture *assets);

    Bari(int, int);
    /**
     * this is a default constructor for barrier 
     */
    Bari();
    ~Bari();
    SDL_Rect posi();
};
