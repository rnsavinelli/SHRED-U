/*
 * collisions.h
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

#ifndef ASTEROID_H
#define ASTEROID_H

#include "SDL_handler.h"
#include "player.h"
#include <stdbool.h>

#define ASTEROID_SPEED	300
#define N_ASTEROIDS	4

struct Asteroid {
    bool status;
    SDL_Rect position;
    struct Speed speed;
};

void AsteroidInit(struct Asteroid *asteroid);

#endif
