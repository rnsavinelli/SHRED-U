/*
 * player.c
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

#include <stdlib.h>

#include "SDL_handler.h"
#include "player.h"
#include "game.h"

void playerInit(int window_width, int window_height, struct Player *player)
{
    extern SDL_Resources core;

    player->tolerance = 100;
    player->score = 0;
    player->hp = 3;

    SDL_QueryTexture(core.textures.player, NULL, NULL,
					&(player->position.w),
					&(player->position.h));

    player->position.x = (window_width - player->position.w) / 2;
    player->position.y = (window_height - player->position.h);

    player->speed.x = 0;
    player->speed.y = 0;
}

void playerBounds(int window_width, int window_height, struct Player *player)
{	
	bool flag = false;
	
	if (player->position.x < window_width/4) {
        player->position.x = window_width/4;
        flag = true;
    }

    if (player->position.y < 0) {
        player->position.y = 0;
		flag = true;
    }

    if (player->position.x > window_width - player->position.w - window_width/4) {
        player->position.x = window_width - player->position.w - window_width/4;
		flag = true;
    }

    if (player->position.y > window_height - player->position.h) {
        player->position.y = window_height - player->position.h;
		flag = true;
    }
    
    if (flag) {
		printf("[PLAYER] Bound reached.\n");
	}
}

void player(int window_width, int window_height, struct Player *player)
{
    extern struct KeyboardInput key_pressed;

    playerDraw(player);

    player->speed.x = 0;
    player->speed.y = 0;

    if (key_pressed.up && !key_pressed.down) {
        player->speed.y = DEFAULT_SPEED;
    }

    if (key_pressed.down && !key_pressed.up) {
        player->speed.y = -3*(DEFAULT_SPEED/4);
    }

    if (key_pressed.left && !key_pressed.right) {
        player->speed.x = -DEFAULT_SPEED;
    }

    if (key_pressed.right && !key_pressed.left) {
        player->speed.x = DEFAULT_SPEED;
    }

    player->position.x += (int) player->speed.x/100;
    player->position.y -= (int) player->speed.y/100;    
}

void playerDraw(struct Player *player)
{
    extern SDL_Resources core;
	
	SDL_RenderCopy(core.renderer, core.textures.player, 
					NULL, &(player->position));
}

/**********************************************************************/

void bulletsInit(int window_width, int window_height, struct Player *player) {	
    for (int i = 0; i < N_BULLETS; i++) {
        player->bullets[i].status = false;
        player->bullets[i].position.x = window_width;
        player->bullets[i].position.y = window_height;
	}
}

void bullets(int window_width, int window_height, struct Player *player){
	bulletsHandler(window_width, window_height, player);
	bulletsMove(window_width, window_height, player);
	bulletsDraw(player);
}

void bulletsHandler(int window_width, int window_height, struct Player *player)
{
    extern struct KeyboardInput key_pressed;

    int variant = rand()%2;

    if (key_pressed.space) {
		for (int i = 0; i < N_BULLETS; i++) {
			if(!(player->bullets[i]).status) {
				(player->bullets[i]).status = true;
				
				(player->bullets[i]).position.x = player->position.x + player->position.w/2
												- (player->bullets[i]).position.w/2;

				(player->bullets[i]).position.y = player->position.y + player->bullets[i].position.h/2;

				if (variant == 0) {
					player->bullets[i].texture = core.textures.bullet_zero;
				}

				else if (variant == 1) {
					player->bullets[i].texture = core.textures.bullet_one;
				}

				break;
			}
		}
	}
}

void bulletsMove(int window_width, int window_height, struct Player *player){
	extern SDL_Resources core;

    for (int i = 0; i < N_BULLETS; i++) {
        if(player->bullets[i].status) {
            player->bullets[i].position.y -= (int) BULLET_SPEED/100;

			SDL_RenderCopy(core.renderer, player->bullets[i].texture,
							NULL, &(player->bullets[i].position));

        }
    }	
}

void bulletsBounds(int window_width, int window_height, struct Player *player) {
    for (int i = 0; i < N_BULLETS; i++) {
        if(player->bullets[i].status) {
            if( player->bullets[i].position.y < 0 || 
				player->bullets[i].position.y > window_height) {
				player->bullets[i].status = false;
                player->bullets[i].position.y = window_height;
                player->bullets[i].position.x = window_width;
            }
        }
    }	
}

void bulletsDraw(struct Player *player)
{
    extern SDL_Resources core;
    
	for (int i = 0; i < N_BULLETS; i++) {
		if(player->bullets[i].status)
			SDL_QueryTexture(player->bullets[i].texture, NULL, NULL,
								&(player->bullets[i].position.w),
								&(player->bullets[i].position.h));	
	}
}
