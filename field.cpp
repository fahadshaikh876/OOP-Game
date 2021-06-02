#include "field.hpp"
#include <iostream>
/**
 * this class is basically setting up the field for the game 
 * its drawing the objects that are part of the game by picking them from assets.png 
 * the positions of the barriers can be seen here 
 * we aim to add more to it 
 */

void Field::drawObjects()
{
    for (list<Bullet *>::iterator i = shooter.begin(); i != shooter.end(); i++)
    {
        (*i)->draw(gRenderer, assets);
        if ((*i)->getmoverx() > 1300)
        {
            delete (*i);
            i = shooter.erase(i);
        }
    }

    for (list<Bari *>::iterator i = bari1.begin(); i != bari1.end(); i++)
    {

        (*i)->draw(gRenderer, assets);
    }

    for (list<Bari2 *>::iterator j = barii2.begin(); j != barii2.end(); j++)
    {

        (*j)->draw(gRenderer, assets);
    }

    for (list<lifeTrack *>::iterator s = lifetra.begin(); s != lifetra.end(); s++)
    {

        (*s)->draw(gRenderer, assets);
    }

    if (!boomAnimate.empty())
    {
        boomAnimate.back()->draw(gRenderer, assets);
    }

    if (!gameEnd.empty())
    {
        gameEnd.back()->draw(gRenderer, assets);
    }
}

void Field::createObject(int x, int y, char p)
{
    boomAnimate.push_back(new Boom(x, y));
    gameEnd.push_back(new GameOver());
}

int Field::createObject(int x, int y)
{
    if (y % 50 == 0)
    {
        cout << "This is the value of x: " << y << endl;
        shooter.push_back(new Bullet(x, y));
        return 1;
    }
    else
    {
        return 0;
    }
}

void Field::createObject()
{
    bari1.push_back(new Bari(1200, (rand() % 600)));
    //bari1.push_back(new Bari(400, (rand() % 600)));
    bari1.push_back(new Bari(900, (rand() % 600)));
    
    barii2.push_back(new Bari2(700, (rand() % 600)));
    barii2.push_back(new Bari2(500, (rand() % 600)));
    barii2.push_back(new Bari2(1050, (rand() % 600)));

    lifetra.push_back(new lifeTrack(1));
    lifetra.push_back(new lifeTrack(2));
    lifetra.push_back(new lifeTrack(3));
    lifetra.push_back(new lifeTrack(4));
    lifetra.push_back(new lifeTrack(5));
}

void Field::deleteALL()
{
    for (auto i = bari1.begin(); i != bari1.end(); i++)
    {
        delete bari1.back();
        bari1.pop_back();
    }
    bari1.clear();

    for (auto i = barii2.begin(); i != barii2.end(); i++)
    {
        delete barii2.back();
        barii2.pop_back();
    }
    barii2.clear();

    for (auto i = lifetra.begin(); i != lifetra.end(); i++)
    {
        delete lifetra.back();
        lifetra.pop_back();
    }
    lifetra.clear();

    for (auto i = shooter.begin(); i != shooter.end(); i++)
    {
        delete shooter.back();
        shooter.pop_back();
    }
    shooter.clear();

    for (auto i = boomAnimate.begin(); i != boomAnimate.end(); i++)
    {
        delete boomAnimate.back();
        boomAnimate.pop_back();
    }
    boomAnimate.clear();
}

Field::Field(SDL_Renderer *renderer, SDL_Texture *asst) : gRenderer(renderer), assets(asst) {}

// Field::~Field()
// {
// }
