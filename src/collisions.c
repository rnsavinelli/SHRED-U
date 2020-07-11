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

#include "game.h"
#include "main.h"
#include "collisions.h"

void BoundDetection(int window_w, int window_h, GameData *game)
{
	playerBounds(window_w, window_h, &(game->player));
	bulletsBounds(window_w, window_h, &(game->player));
	enemiesBounds(window_w, window_h, game->enemy);
	asteroidsBounds(window_w, window_h, game->asteroid);
}

bool CollisionDetection(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
{
    /* no collision */
    if ( (x1 > x2 + w2 - 1) || (y1 > y2 + h2 - 1) || (x2 > x1 + w1 - 1) || (y2 > y1 + h1 - 1) ) {
        return false;
    }

    /* collision */
	printf("[STATUS] Collision detected.\n");
    return true;
}

bool CollisionHandler(int window_width, int window_height, GameData *game)
{
    bool collision = false;
   
    int x = game->player.position.x;
    int y = game->player.position.y;

    int player_w = game->player.position.w;
    int player_h = game->player.position.h;
    
	int bullet_x = 0, bullet_y = 0;
    int bullet_w = game->player.bullets->position.w;
    int bullet_h = game->player.bullets->position.h;

	int asteroid_x = 0, asteroid_y = 0;
    int asteroid_w = game->asteroid->position.w;
    int asteroid_h = game->asteroid->position.h;
	
	int enemy_x = 0, enemy_y = 0;
    int enemy_w = game->enemy->position.w;
    int enemy_h = game->enemy->position.h;

    for(int j = 0; j < N_ASTEROIDS; j++) {
        asteroid_x = game->asteroid[j].position.x;
        asteroid_y = game->asteroid[j].position.y;

        if(CollisionDetection(x - player_w/2, y - player_h/2, player_w,
            player_h, asteroid_x - asteroid_w/2, asteroid_y - asteroid_h/2,
            asteroid_w,  asteroid_h) ) {

            for(int i = 0; i < N_BULLETS; i++) {
                (game->player.bullets[j]).status = false;
            }

            collision = true;
        }
    }

    for(int j = 0; j < N_ROWS; j++) {
        for(int i = 0; i < N_ENEMIES; i++) {
            enemy_x = game->enemy[(N_ENEMIES * j) + i].position.x;
            enemy_y = game->enemy[(N_ENEMIES * j) + i].position.y;

            if(CollisionDetection(x - player_w/2, y - player_h/2, player_w,
                player_h, enemy_x - enemy_w/2, enemy_y - enemy_h/2,
                enemy_w, enemy_h) ) {

                for(int k = 0; k < N_BULLETS; k++) {
                    (game->player.bullets[k]).status = false;
                }

                collision = true;
            }

			for(int k = 0; k < N_BULLETS; k++) {
				if(game->player.bullets[k].status == true) {
					bullet_y = game->player.bullets[k].position.y;
					bullet_x = game->player.bullets[k].position.x;
                
					if(CollisionDetection(enemy_x - enemy_w/2, enemy_y - enemy_h/2, enemy_w, enemy_h,
						bullet_x - bullet_w/2, bullet_y - bullet_h/2,
						bullet_w, bullet_h) ) {

						game->player.bullets[k].status = false;
						game->player.bullets[k].position.x = window_width;
						game->player.bullets[k].position.y = 0;
						game->enemy[(N_ENEMIES * j) + i].status = false;
						game->enemy[(N_ENEMIES * j) + i].position.x = window_width + (2 * enemy_w);
						game->player.score += 5;
					}
                }
            }
        }
    }

    return collision;
}
