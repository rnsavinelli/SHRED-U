/*
 * collisions.c
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

#include "collisions.h"

void BoundDetection(int window_w, int window_h, GameData *game)
{
	if (game->player.position.x <= 0) {
        game->player.position.x = 0;
    }

	if (game->player.position.y <= 0) {
        game->player.position.y = 0;
    }

	if (game->player.position.x >= window_w - game->player.position.w) {
        game->player.position.x = window_w - game->player.position.w;
    }

	if (game->player.position.y >= window_h - game->player.position.h) {
        game->player.position.y = window_h - game->player.position.h;
    }
}
