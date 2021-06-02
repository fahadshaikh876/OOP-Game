#include <SDL.h>
#include <iostream>
#pragma once
using namespace std;

// THIS CLASS IS INHERITED IN MOST OF THE OTHER CLASSES
// IT HANNDLES ALL DRAWING FUNCTIONS AND ALL CONSTANTS THAT ARE USED IN OTHER CLASS
class Unit
{
protected:
    SDL_Rect srcRect, moverRect;

public:
    void draw(SDL_Renderer *, SDL_Texture *assets);

    ~Unit(); // DELETE
};
