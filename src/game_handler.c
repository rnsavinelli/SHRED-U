#include "main.h"
#include "SDL_handler.h"
#include "game_handler.h"

/* Initializes game variables */
void init_game(struct Resources *core, struct Player *data)
{
	data->status = 0;
	data->score = 0;
	data->hp = 3;
	
	/* Player's position */
	SDL_QueryTexture(core->textures.player, NULL, NULL, &(data->position.w), &(data->position.h));
	data->position.x = (WINDOW_WIDTH - data->position.w) / 2;
	data->position.y = (WINDOW_HEIGHT - data->position.h);
	
	data->speed.x = DEFAULT_SPEED;
	data->speed.y = DEFAULT_SPEED;
}

void run_game(struct Resources *core, struct Player *data)
{
	bool close_window = FALSE;
	
	while (close_window != TRUE) {
        SDL_Event event_quit;
        
        while (SDL_PollEvent(&event_quit)) {
            if (event_quit.type == SDL_QUIT) {
				printf("SDL_QUIT event successfully requested.\n");
                close_window = TRUE;
            }
        }
        
        if (data->position.x <= 0) {
            data->position.x = 0;
            data->speed.x = -data->speed.x;
        }
        
        if (data->position.y <= 0) {
            data->position.y = 0;
            data->speed.y = -data->speed.y;
        }
        
        if (data->position.x >= WINDOW_WIDTH - data->position.w) {
            data->position.x = WINDOW_WIDTH - data->position.w;
            data->speed.x = -data->speed.x;
        }
        
        if (data->position.y >= WINDOW_HEIGHT - data->position.h) {
            data->position.y = WINDOW_HEIGHT - data->position.h;
            data->speed.y = -data->speed.y;
        }
        
        data->position.x += (int) data->speed.x/100;
        data->position.y -= (int) data->speed.y/100;
        
        SDL_RenderClear(core->renderer);
        
		SDL_RenderCopy(core->renderer, core->textures.player, NULL, &(data->position));
        
        SDL_RenderPresent(core->renderer);
        SDL_Delay(1000/60);
	}
}

void quit_game(struct Player *data) {
	
}
