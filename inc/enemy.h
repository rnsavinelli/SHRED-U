/*
 * enemy.h
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

#ifndef ENEMY_H
#define ENEMY_H

#include "SDL_handler.h"
#include "player.h"
#include <stdbool.h>

#define ENEMY_SPEED             1
#define ENEMY_SPEED_INCREMENT   1
#define N_ENEMIES	            10
#define N_ROWS		            3

struct Enemy {
    bool status;
    SDL_Rect position;
    struct Speed speed;
};

void EnemiesInit(int window_width, int window_height, struct Enemy *enemy);
void EnemiesGenerate(int window_width, int window_height, struct Enemy *enemy);
void EnemiesMove(int window_width, int window_height, struct Enemy *enemy);
void Enemies(int window_width, int window_height, struct Enemy *enemy);
void EnemiesDraw(struct Enemy *enemy);

#endif
