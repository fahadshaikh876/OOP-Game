#include <SDL.h>
#include <iostream>
#include <list>
using namespace std;

class Boom : public Unit
{
public:
    void draw(SDL_Renderer *, SDL_Texture *assets);
    Boom(int, int);
    Boom();
    SDL_Rect posi();
    ~Boom();
};