/*
 * SDL_window.h
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

#ifndef SDL_WINDOW_H
#define SDL_WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

#define WINDOW_TITLE "SHRED -U: The Game"

#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 540

#define ERROR 1

int create_window(SDL_Window **window);
int create_renderer(SDL_Renderer **renderer, SDL_Window **window);

void destroy_window(SDL_Window **window);
void destroy_renderer(SDL_Renderer **renderer);

#endif
