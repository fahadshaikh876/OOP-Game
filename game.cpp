#include "game.hpp"
#include <iostream>
#include <stack>
#include "unit.hpp"
using namespace std;
/** \brief this is the basic game class which sets up everything for our game 
 * initialization of the sdl and the media is loaded using it 
 * this also intializes the audio and loads media 
 * it would print a message to indicate in case media loading fails 
 */
bool Game::init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		gWindow = SDL_CreateWindow("Save Your Helicopter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	bool success = true;

	assets = loadTexture("assets.png");
	gTexture = loadTexture("menu.png");
	if (assets == NULL || gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	bgMusic = Mix_LoadMUS("helicoptersound.mp3");
	CrashMusic = Mix_LoadWAV("Crash.mp3");
	BulletMusic = Mix_LoadWAV("Sniper.mp3");
	LifeSound = Mix_LoadWAV("lifetrimmed.mp3");
	if (bgMusic == NULL)
	{
		printf("Unable to load music: %s \n", Mix_GetError());
		success = false;
	}
	if (CrashMusic == NULL)
	{
		printf("Unable to load crash music: %s \n", Mix_GetError());
		success = false;
	}
	if (BulletMusic == NULL)
	{
		printf("Unable to load bullet music: %s \n", Mix_GetError());
		success = false;
	}
	if (LifeSound == NULL)
	{
		printf("Unable to load life music: %s \n", Mix_GetError());
		success = false;
	}
	return success;
}

void Game::close()
{
	SDL_DestroyTexture(assets);
	assets = NULL;
	SDL_DestroyTexture(gTexture);
	SDL_DestroyRenderer(gRenderer);
	Mix_FreeChunk(CrashMusic);
	Mix_FreeChunk(LifeSound);
	Mix_FreeChunk(BulletMusic);
	CrashMusic = NULL;
	LifeSound = NULL;
	BulletMusic = NULL;
	gWindow = NULL;
	gRenderer = NULL;
	Mix_FreeMusic(bgMusic);
	bgMusic = NULL;
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();

	cout << "objects deleted and all memomry free";
}

SDL_Texture *Game::loadTexture(std::string path)
{
	SDL_Texture *newTexture = NULL;
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		m_width = loadedSurface->w;
		m_height = loadedSurface->h;
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}
void Game::run()
{
	// SDL_Event e;
	Field field(gRenderer, assets);

	field.createObject();

	while (!check)
	{
		SDL_RenderCopyEx(gRenderer, gTexture, NULL, NULL, 0, 0, SDL_FLIP_NONE);
		SDL_RenderPresent(gRenderer);
		int xMouse, yMouse;

		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				SDL_GetMouseState(&xMouse, &yMouse);
				cout << xMouse << " & " << yMouse << endl;

				if (xMouse > 35 && xMouse < 190 && yMouse > 164 && yMouse < 253)
				{

					quit = false;
					check = true;
					gTexture = loadTexture("bg.png");
				}

				if (xMouse > 1045 && xMouse < 1165 && yMouse > 164 && yMouse < 253)
				{
					quit = true;
					check = true;
				}
			}
		}
	}
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			if (intersected == false)
			{
				dot->handleEvent(e);
			}
			int soundbullet = field.createObject(gunbarrel->getmoverx(), gunbarrel->getmovery());
			if (soundbullet == 1)
			{
				Mix_PlayChannel(-1, BulletMusic, 0);
			}
		}
		dot->move();
		SDL_Rect rect1 = dot->posi();

		for (list<Bari2 *>::iterator i = field.barii2.begin(); i != field.barii2.end(); i++)
		{
			SDL_Rect rect2 = (*i)->posi();
			if (SDL_HasIntersection(&rect1, &rect2))
			{
				intersected = true;
				interscBarier = true;
			}
		}

		for (list<Bullet *>::iterator b = field.shooter.begin(); b != field.shooter.end(); b++)
		{
			SDL_Rect rect4 = (*b)->posi();
			if (SDL_HasIntersection(&rect1, &rect4))
			{
				intersected = true;
			}
		}

		for (list<Bari *>::iterator k = field.bari1.begin(); k != field.bari1.end(); k++)
		{
			SDL_Rect rect3 = (*k)->posi();

			if (SDL_HasIntersection(&rect1, &rect3))
			{
				intersected = true;
				interscBarier = true;
			}
		}

		if (intersected == true && interscBarier == false)
		{
			if (field.lifetra.empty() == false)
			{
				list<lifeTrack *>::iterator it1;
				it1 = field.lifetra.begin();

				int whichLifeRemove = field.lifetra.size() - 1;
				Mix_PlayChannel(-1, LifeSound, 0);
				advance(it1, whichLifeRemove);
				cout << "THIS LIFE REMOVE at VAL" << whichLifeRemove << endl;
				it1 = field.lifetra.erase(it1);
				dot->collision();
				intersected = false;
			}
			else
			{
				Crasher = 1;
				if (Crasher == 1 && Crashloop == 0)
				{
					Mix_PlayChannel(-1, CrashMusic, 0);
					Crashloop = 1;
				}
				if (dot->posi().y < 575)
				{
					field.createObject((dot->posi().x), (dot->posi().y), 'a');
					dot->posi().y += 5;
				}
				else
				{
					intersected = false;

					break;
				}
			}
		}
		else if (intersected == true && interscBarier == true)
		{
			field.createObject((dot->posi().x), (dot->posi().y), 'a');
			Crasher = 1;
			if (Crasher == 1 && Crashloop == 0)
			{
				Mix_PlayChannel(-1, CrashMusic, 0);
				Crashloop = 1;
			}
			if (dot->posi().y < 575)
			{
				dot->posi().y += 5;
			}
			else
			{
				intersected = false;

				break;
			}
		}
		gunbarrel->mover();

		if (Mix_PlayingMusic() == 0)
		{
			Mix_PlayMusic(bgMusic, 2);
			int Mix_VolumeMusic(30);
		}

		scrollingOffset -= 6;
		if (scrollingOffset < -m_width)
		{
			scrollingOffset = 0;
		}

		SDL_RenderClear(gRenderer);

		SDL_Rect renderQuad = {scrollingOffset, 0, m_width, m_height};
		SDL_RenderCopyEx(gRenderer, gTexture, NULL, &renderQuad, 0, 0, SDL_FLIP_NONE);

		renderQuad = {scrollingOffset + m_width, 0, m_width, m_height};
		SDL_RenderCopyEx(gRenderer, gTexture, NULL, &renderQuad, 0, 0, SDL_FLIP_NONE);

		field.drawObjects();

		gunbarrel->draw(gRenderer, assets);
		dot->draw(gRenderer, assets);

		SDL_RenderPresent(gRenderer);

		SDL_Delay(25);
	}
	field.deleteALL();
	dot = NULL;
	delete dot;

	gunbarrel = NULL;
	delete gunbarrel;

	// close();
}