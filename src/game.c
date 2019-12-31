/*
 * game.c
 * 
 * Copyright 2019 Roberto Nicolás Savinelli <rnsavinelli@est.frba.utn.edu.ar>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#include "SDL_handler.h"
#include "game.h"

/* Initializes game variables */
void init_game(struct Resources *core, struct Game *data)
{
	data->player.status = 0;
	data->player.score = 0;
	data->player.hp = 3;
	
	/* Player's position */
	SDL_QueryTexture(core->textures.player, NULL, NULL, &(data->player.position.w), &(data->player.position.h));
	data->player.position.x = (WINDOW_WIDTH - data->player.position.w) / 2;
	data->player.position.y = (WINDOW_HEIGHT - data->player.position.h);
	
	data->player.speed.x = DEFAULT_SPEED;
	data->player.speed.y = DEFAULT_SPEED;
}

void run_game(struct Resources *core, struct Game*data)
{
	bool close_window = false;
	
	while (close_window != true) {
        SDL_Event event_quit;
        
        while (SDL_PollEvent(&event_quit)) {
            if (event_quit.type == SDL_QUIT) {
				printf("SDL_QUIT event successfully requested.\n");
                close_window = true;
            }
        }
        
        if (data->player.position.x <= 0) {
            data->player.position.x = 0;
            data->player.speed.x = -data->player.speed.x;
        }
        
        if (data->player.position.y <= 0) {
            data->player.position.y = 0;
            data->player.speed.y = -data->player.speed.y;
        }
        
        if (data->player.position.x >= WINDOW_WIDTH - data->player.position.w) {
            data->player.position.x = WINDOW_WIDTH - data->player.position.w;
            data->player.speed.x = -data->player.speed.x;
        }
        
        if (data->player.position.y >= WINDOW_HEIGHT - data->player.position.h) {
            data->player.position.y = WINDOW_HEIGHT - data->player.position.h;
            data->player.speed.y = -data->player.speed.y;
        }
        
        data->player.position.x += (int) data->player.speed.x/100;
        data->player.position.y -= (int) data->player.speed.y/100;
        
        SDL_RenderClear(core->renderer);
        
		SDL_RenderCopy(core->renderer, core->textures.player, NULL, &(data->player.position));
        
        SDL_RenderPresent(core->renderer);
        SDL_Delay(1000/60);
	}
}

void quit_game(struct Game *data) {
	
}
