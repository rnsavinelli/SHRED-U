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

#include <stdbool.h>
#include "SDL_handler.h"

#define ASTEROID_SPEED	150
#define N_ASTEROIDS	3

struct Asteroid {
    SDL_Rect position;
};

void AsteroidsInit(int window_width, int window_height, struct Asteroid *asteroid);

void Asteroids(int window_width, int window_height, struct Asteroid *asteroid);

#endif
