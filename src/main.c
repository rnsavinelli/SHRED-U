#include "main.h"
#include "game_handler.h"
#include "SDL_handler.h"

int main(void)
{
	struct Resources sdl_resources;
	struct Player data;
    	
	if(init_resources(&sdl_resources) != ERROR) {
		init_game(&sdl_resources, &data);
		run_game(&sdl_resources, &data);
	}
	
	clean_resources(&sdl_resources);
	quit_game(&data);
	
    return 0;
}
