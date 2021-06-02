#include <SDL.h>
#include <list>
#include "helicopter.hpp"
#include "barier.hpp"
#include "gun.hpp"
#include "barr2.hpp"
#include <vector>
#include "lifetrack.hpp"
#include "boom.hpp"
#include "GameOver.hpp"

using namespace std;
/**
 * \brief this class is basically setting up the field for the game 
 */
class Field
{
protected:
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;

public:
    list<Bullet *> shooter;
    list<Bari2 *> barii2;
    list<Bari *> bari1;
    list<lifeTrack *> lifetra; 
    list<Boom *> boomAnimate;
    list<GameOver*> gameEnd;
    Field(SDL_Renderer *, SDL_Texture *);
    void drawObjects();
    void createObject(int, int, char);
    int createObject(int, int);
    void createObject();
    void deleteALL();
    // ~Field();
};