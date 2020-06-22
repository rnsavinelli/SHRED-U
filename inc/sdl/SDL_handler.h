/*
 * SDL_handler.h
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

#ifndef SDL_HANDLER_H
#define SDL_HANDLER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "SDL_window.h"
#include "SDL_textures.h"
#include "SDL_keyboard.h"
#include "SDL_fonts.h"

#define ERROR 1

typedef struct Resources {
    SDL_Window *window;
    SDL_Renderer *renderer;

    struct Textures textures;
    struct Fonts fonts;
}
SDL_Resources;

extern SDL_Resources core;

int SDL_InitResources(SDL_Resources *sdl);
void SDL_CleanResources(SDL_Resources *sdl);

#endif
