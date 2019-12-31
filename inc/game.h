/*
 * game.h
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

#ifndef GAME_H
#define GAME_H

#include "SDL_handler.h"
#include <stdbool.h>

#define DEFAULT_SPEED	300
#define BULLET_SPEED	300
#define ASTEROID_SPEED	300

#define N_BULLETS	20
#define N_ASTEROIDS	4
#define N_ENEMIES	30
#define N_ROWS		3

#define ERROR 1

enum APP_MENU {
    MENU_MAIN_MENU,
    MENU_GAME_START,
    MENU_GAME_RESTART,
    MENU_GAME_OVER,
    MENU_INSERT_NAME,
    MENU_EXIT
};

struct Speed {
	float x;
	float y;
};

struct Bullets {
	bool status;
	float x;
	float y;
};

struct Player {
	int status;
	int tolerance;
	int score;
	int hp;
	SDL_Rect position;
	struct Speed speed;
	struct Bullets bullets[N_BULLETS];
};

struct Enemy {
	bool status;
	SDL_Rect position;
	struct Speed speed;
};

struct Asteroid {
	bool status;
	SDL_Rect position;
	struct Speed speed;
};

struct Game {	
	struct Player player;
	struct Enemy enemy[N_ENEMIES];
	struct Asteroid asteroid[N_ASTEROIDS];
};

void init_game(struct Resources *core, struct Game *data);
void run_game(struct Resources *core, struct Game *data);
void quit_game(struct Game *data);

#endif
