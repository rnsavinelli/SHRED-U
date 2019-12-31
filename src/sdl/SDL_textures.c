/*
 * SDL_textures.h
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

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include "SDL_textures.h"

/* Loads game textures to memory */
int create_texture(SDL_Renderer **renderer, SDL_Texture **texture, char *image_path)
{
    SDL_Surface *surface = NULL;

    /* Player's surface*/
    surface = IMG_Load(image_path);
    if (surface == NULL) {
        printf("Error loading surface.\n");
        return ERROR;
    }

    else {
        *texture = SDL_CreateTextureFromSurface(*renderer, surface);
        SDL_FreeSurface(surface);

        if (*texture == NULL) {
            printf("Error creating texture: %s\n", SDL_GetError());
            return ERROR;
        }
    }

    return 0;
}
