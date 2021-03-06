/*
 * collisions.h
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

#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <stdbool.h>

#include "game.h"
#include "main.h"

void BoundDetection(int window_width, int window_height, GameData *data);

bool CollisionDetection(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);
bool CollisionHandler(int window_width, int window_height, GameData *data);

#endif
