#include "main.h"
#include "SDL_handler.h"

/* Initializes all core functions needed for the game to run */
int init_resources(struct Resources *core)
{	
	printf("Initializing SDL...\n");
	if(SDL_init() == ERROR) {
		return ERROR;
    }
    
	printf("Creating window...\n");
    if(create_window(core) == ERROR ) {
        return ERROR;		
	}
	
	printf("Creating renderer...\n");
	if(create_renderer(core) == ERROR) {
        return ERROR;		
	}
	
	printf("Creating textures...\n");
    if(create_textures(core, &(core->textures.player), PLAYER_ASSET) == ERROR) {
		return ERROR;
	}
	
	if(create_textures(core, &(core->textures.enemy), ENEMY_ASSET) == ERROR) {
		return ERROR;
	}

    if(create_textures(core, &(core->textures.asteroid), ASTEROID_ASSET) == ERROR) {
		return ERROR;
	}

	printf("No problems found.\nLaunching game...\n");
	printf("Enjoy your stay!\n");
	return SUCCESS;
}

int SDL_init(void)
{	
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) != 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError());
	    return ERROR;
	}
	
	else {
		return SUCCESS;
	}
}

/* Creates the window */
int create_window(struct Resources *core)
{	
    core->window = SDL_CreateWindow("SHRED -U: The Game", SDL_WINDOWPOS_CENTERED,
									SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH,
									WINDOW_HEIGHT, 0);
								
    if (core->window == NULL) {
        printf("Error creating window: %s\n", SDL_GetError());
	    return ERROR;
    }
    
    else {
		return SUCCESS;
	}
}

/* Creates the renderer */
int create_renderer(struct Resources *core)
{
	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

	core->renderer = SDL_CreateRenderer(core->window, -1, render_flags);
	
	if (core->renderer == NULL) {
      printf("Error creating SDL renderer: %s\n", SDL_GetError());
      return ERROR;
    }
    
    else {
	    SDL_SetRenderDrawColor(core->renderer, 0, 0, 0, 255);
		SDL_RenderClear(core->renderer);
		SDL_RenderPresent(core->renderer);
		return SUCCESS;
	}
}

/* Loads game textures to memory */
int create_textures(struct Resources* core, SDL_Texture** texture, char* image_path)
{
	SDL_Surface* surface = NULL;
	
	/* Player's surface*/
	surface = IMG_Load(image_path);
	if (surface == NULL) {
        printf("Error loading surface.\n");
        return ERROR;
    }
    
    else {
	    *texture = SDL_CreateTextureFromSurface(core->renderer, surface);
		SDL_FreeSurface(surface);
	
		if (*texture == NULL) {
			printf("Error creating texture: %s\n", SDL_GetError());
			return ERROR;
		}
	}
	
	return 0;
}

/* Cleans all used resources */
void clean_resources(struct Resources *core)
{
	if(core->textures.player != NULL) {
		SDL_DestroyTexture(core->textures.player);
	}
	
	if(core->renderer != NULL) {
		SDL_DestroyRenderer(core->renderer);
	}
	
	if(core->window != NULL) {
		SDL_DestroyWindow(core->window);
	}
	
    SDL_Quit();
    printf("All initialized SDL subsystems were cleaned up.\n");
    return;
}
