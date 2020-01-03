/*
 * player.h
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

#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "player.h"

#define N_BULLETS	20

#define DEFAULT_SPEED	400
#define BULLET_SPEED	300

#define DEFAULT_TOLERANCE	100
#define DEFAULT_HP			3

#define OFF 1
#define ON	0

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
    int tolerance;
    int score;
    int hp;
    SDL_Rect position;
    struct Speed speed;
    struct Bullets bullets[N_BULLETS];
};

void PlayerInit(struct Player *player);

void PlayerMovement(struct Player *player);

#endif
