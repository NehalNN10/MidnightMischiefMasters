#include "game.hpp"
#include "MidMischief.hpp"
#include "Drawing.hpp"
#include <iostream>

SDL_Renderer *Drawing::gRenderer = NULL;
SDL_Texture *Drawing::assets = NULL;
SDL_Texture *Drawing::collect = NULL;

static int screen = 0; // decides whether game runs or not

/*
0 = starting screen
1 = playing screen
2 = pause screen
3 = how to play
4 = credits
5 = controls
*/

bool Game::init()
{
	// Initialization flag
	bool success = true;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		// Create window
		gWindow = SDL_CreateWindow("Midnight Mischief Masters", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			// Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (Drawing::gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				// Initialize renderer color
				SDL_SetRenderDrawColor(Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				// Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}

				// initialising mixer
				// if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
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

bool Game::gameStart()
{
	// Loading success flag
	bool success = true;
	gTexture = loadTexture("background.jpg");
	screen = 1;
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

bool Game::gamePause()
{
	// Loading success flag
	bool success = true;
	gTexture = loadTexture("pause_screen.jpg");
	screen = 2;
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

bool Game::credits()
{
	// Loading success flag
	bool success = true;
	gTexture = loadTexture("pause_screen.jpg");
	screen = 4;
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

bool Game::how_to_play()
{
	bool success = true;
	gTexture = loadTexture("How to play.png");
	screen = 3;
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

bool Game::controls()
{
	bool success = true;
	gTexture = loadTexture("controls.png");
	screen = 5;
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}


bool Game::loadMedia()
{
	// Loading success flag
	bool success = true;
	screen = 0;
	Drawing::assets = loadTexture("assets.png");
	Drawing::collect = loadTexture("collect.png");
	// gTexture = loadTexture("background.jpg");
	gTexture = loadTexture("Midnight mischief masters.png");
	if (gTexture == NULL || Drawing::assets == NULL || Drawing::collect == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	// playing background music
	gMusic = Mix_LoadMUS("bgmusic.mp3");
	if (gMusic == NULL)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	std::cout << "Music being played tho" << std::endl;
	return success;
}

void Game::close()
{
	// Free loaded images
	SDL_DestroyTexture(Drawing::assets);
	Drawing::assets = NULL;
	SDL_DestroyTexture(gTexture);
	SDL_DestroyTexture(Drawing::collect);
	Drawing::collect = NULL;

	// Destroy window
	SDL_DestroyRenderer(Drawing::gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	// Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	// handle music player
	// Stop playing the music if it's playing
	if (Mix_PlayingMusic())
	{
		Mix_HaltMusic();
	}

	// Free the music object
	if (gMusic != NULL)
	{
		Mix_FreeMusic(gMusic);
		gMusic = NULL;
	}

	// Quit SDL Mixer
	Mix_Quit();
}

SDL_Texture *Game::loadTexture(std::string path)
{
	// The final texture
	SDL_Texture *newTexture = NULL;

	// Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		// Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(Drawing::gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		// Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

void Game::run()
{
	bool quit = false;
	SDL_Event e;
	MidMischief *midnight = new MidMischief(); // game object, all game functions should be in MidMischief class
	// dynamic allocation
	midnight->toggle_paused(false);

	while (!quit)
	{
		// Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			// User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			const Uint8 *currentKeyStates = SDL_GetKeyboardState(nullptr);

			// to click play, rules, quit, hard screen, medium screen, easy screen
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);
				std::cout << "X: " << xMouse << ", Y: " << yMouse << std::endl;
				if (xMouse > 432 && xMouse < 584 && yMouse > 343 && yMouse < 370 && screen == 0)
				{
					gameStart();
				}
				else if (xMouse > 349 && xMouse < 669 && yMouse > 417 && yMouse < 444 && screen == 0)
				{
					how_to_play();
				}
				else if (xMouse > 399 && xMouse < 596 && yMouse > 510 && yMouse < 572 && screen == 3)
				{
					controls();
				}
			}

			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
			{
				if (screen == 3) //go back to main screen when you press ESCAPE in How to Play screen
					loadMedia();
				else if (screen == 5) // go back to How to Play when you press ESCAPE in controls screen
					how_to_play();
			}

			// to pause and unpause the screen
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_p)
			{
				if (midnight->getpaused() == false)
				{
					midnight->toggle_paused(true);
					gamePause();
				}
				else if (midnight->getpaused() == true)
				{
					midnight->toggle_paused(false);
					gameStart();
				}
			}

			// Handle movement
			if (!midnight->getpaused())
			{
				// Call your function to handle character movement
				midnight->movechars(currentKeyStates);
			}
			if (Mix_PlayingMusic()==0 && (screen !=1 && screen != 2)) //playing music here
			{
				Mix_PlayMusic(gMusic, -1);
			}
			else
			{
				if (Mix_PlayingMusic() && screen == 1 && screen == 2)
					Mix_HaltMusic();
			}
		}

		SDL_RenderClear(Drawing::gRenderer);					  // removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL); // Draws background to renderer

		//***********************draw the objects here********************

		if (screen == 1)
		{
			// draws both characs
			midnight->drawchars();
			// moving the characters down
			midnight->apply_gravity();
			// animates both characs
			midnight->animatechars();
			// check if collisions b/w characters
			// std::cout << midnight->checkCollision();
			midnight -> allCollisions();
			midnight->text_score();
			midnight->show_score();
		}

		SDL_RenderPresent(Drawing::gRenderer); // displays the updated renderer

		SDL_Delay(40); // causes sdl engine to delay for specified miliseconds
	}
	delete midnight;
	midnight = nullptr;
}
