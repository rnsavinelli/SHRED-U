/*
 * enemy.c
 *
 * Copyright 2020 Roberto Nicolás Savinelli <rnsavinelli@est.frba.utn.edu.ar>
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

#include "enemy.h"

void EnemiesInit(int window_width, int window_height, struct Enemy *enemy)
{
	extern SDL_Resources core;

    for(int i = 0; i < N_ENEMIES*N_ROWS; i++) {
        enemy[i].status = false;

		SDL_QueryTexture(core.textures.enemy, NULL, NULL,
						&(enemy[i].position.w),
						&(enemy[i].position.h));

        enemy[i].position.x = 0;
		enemy[i].position.y = 0;

        enemy[i].speed.x = 0;
        enemy[i].speed.y = ENEMY_SPEED;
	}
}

void Enemies(int window_width, int window_height, struct Enemy *enemy)
{
    EnemiesGenerate(window_width, window_height, enemy);
    EnemiesMove(window_width, window_height, enemy);
    EnemiesDraw(enemy);
}

void EnemiesDraw(struct Enemy *enemy)
{
    extern SDL_Resources core;

    for(int i = 0; i < N_ENEMIES*N_ROWS ; i++)
	SDL_RenderCopy(core.renderer, core.textures.enemy,
						NULL, &(enemy[i].position));
}

void EnemiesGenerate(int window_width, int window_height, struct Enemy *enemy)
{
    int false_enemies = 0;
    int random;
    float k = (window_width/(2 * N_ENEMIES));

    /* if all enemies are set to false: new wave */
    for(int j = 0; j < N_ROWS; j++) {
        for(int i = 0; i < N_ENEMIES; i++) {
            if(!(enemy[(N_ENEMIES * j) + i]).status) {
                false_enemies ++;
            }
        }
    }

    /* symmetric fist wave: not random */
    /* They all have the same speed */
    if (enemy->speed.y == ENEMY_SPEED) {
        random = 2;
    }

    else {
        random = (rand() % 4) + 1;
    }

    /* enemy generation */
    if (false_enemies == N_ENEMIES * N_ROWS) {
        if (random == 1) {
            for(int j = 0; j < N_ROWS; j++) {
                for(int i = 0; i < N_ENEMIES; i++) {
                    enemy[(N_ENEMIES * j) + i].status = true;
                    enemy[(N_ENEMIES * j) + i].position.x = window_width/4 + (k * i);
                    enemy[(N_ENEMIES * j) + i].position.y = -enemy->position.h * (j + 1);
                }
            }

        }

/*
        else if (random == 2) {
            for(j = 0; j < N_ROWS; j++) {
                for(i = 0; i < (N_ENEMIES); i++) {
                    if (i % 2 == 0) {
                        enemy[(N_ENEMIES * j) + i].status = true;
                        enemy[(N_ENEMIES * j) + i].position.x = window_width/4 + (k * i);
                        enemy[(N_ENEMIES * j) + i].position.y = -enemy->position.h * (j + 1) - 32;
                    }

                    else {
                        enemy[(N_ENEMIES * j) + i].status = true;
                        enemy[(N_ENEMIES * j) + i].position.x = window_width/4 + (k * i);
                        enemy[(N_ENEMIES * j) + i].position.y = -enemy->position.h * (j + 1) - 16;
                    }
                }
            }
        }

        else if (random == 3) {
            for(j = 0; j < NUM_FILAS; j++) {
                for(i = 0; i < (NUM_ENEMIES); i++) {
                    if (i % 2 == 0) {
                        (app_struct->enemigo[(NUM_ENEMIES * j) + i]).flag = true;
                        (app_struct->enemigo[(NUM_ENEMIES * j) + i]).x =  window_width/4 + (k * i) + (k/8)*5;
                        (app_struct->enemigo[(NUM_ENEMIES * j) + i]).y = enemy_h*(j+1) + 15;
                    }

                    else {
                        (app_struct->enemigo[(NUM_ENEMIES * j) + i]).flag = true;
                        (app_struct->enemigo[(NUM_ENEMIES * j) + i]).x =  window_width/4 + (k * i) + (k/8)*5;
                        (app_struct->enemigo[(NUM_ENEMIES * j) + i]).y = enemy_h*(j+1) - 25;
                    }
                }
            }
        }
*/

        for(int j = 0; j < N_ROWS; j++)
            for(int i = 0; i < N_ENEMIES; i++)
                 if (enemy[(N_ENEMIES * j) + i].speed.y == ENEMY_SPEED)
                    enemy[(N_ENEMIES * j) + i].speed.y += ENEMY_SPEED_INCREMENT;

        /*else {
            (app_struct->gameplay).velocidad += 0.03;
        }*/
    }

}

void EnemiesMove(int window_width, int window_height, struct Enemy *enemy)
{
    for(int j = 0; j < N_ROWS; j++) {
        for(int i = 0; i < N_ENEMIES; i++) {
            if(enemy[(N_ENEMIES * j) + i].status == true) {
                enemy[(N_ENEMIES * j) + i].position.y += enemy[(N_ENEMIES * j) + i].speed.y;

                if(enemy[(N_ENEMIES * j) + i].position.y > window_height) {
                    enemy[(N_ENEMIES * j) + i].status = false;
                    //((app_struct->gameplay).tolerance)--;
                }
            }
        }
    }
}
