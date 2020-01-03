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

#include "SDL_handler.h"
#include "player.h"
#include "game.h"

void PlayerInit(struct Player *player)
{
	extern SDL_Resources core;

	player->tolerance = 100;
    player->score = 0;
    player->hp = 3;
    
    SDL_QueryTexture(core.textures.player, NULL, NULL, &(player->position.w), &(player->position.h));
    player->position.x = (WINDOW_WIDTH - player->position.w) / 2;
    player->position.y = (WINDOW_HEIGHT - player->position.h);
    
    player->speed.x = 0;
    player->speed.y = 0;
    
    for (int i = 0; i < N_BULLETS; i++) {
		player->bullets[i].status = OFF;
		player->bullets[i].x = 0;
		player->bullets[i].y = 0;
	}
}

void PlayerMovement(struct Player *player)
{
	extern struct KeyboardInput key_pressed;
	
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
