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

bool Game::loadMedia()
{
	// Loading success flag
	bool success = true;

	Drawing::assets = loadTexture("assets.png");
	Drawing::collect = loadTexture("collect.png");
	// gTexture = loadTexture("background.jpg");
	gTexture = loadTexture("starting_screen.jpeg");
	if (gTexture == NULL || Drawing::assets == NULL || Drawing::collect == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
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

			if (currentKeyStates[SDL_SCANCODE_RETURN] && screen == 0)
			{
				// Handle game start
				gameStart();
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
		}

		SDL_RenderClear(Drawing::gRenderer);					  // removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL); // Draws background to renderer

		//***********************draw the objects here********************

		if (screen == 1)
		{
			// draws both characs
			midnight->drawchars();
			// animates both characs
			midnight->animatechars();
			// check if collisions b/w characters
			std::cout << midnight->checkCollision();
		}

		SDL_RenderPresent(Drawing::gRenderer); // displays the updated renderer

		SDL_Delay(100); // causes sdl engine to delay for specified miliseconds
	}
	delete midnight;
	midnight = nullptr;
}
