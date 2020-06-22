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

#ifndef SDL_TEXTURES_H
#define SDL_TEXTURES_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define PLAYER_ASSET	"assets/images/drive-harddisk.png"
#define ENEMY_ASSET		"assets/images/x-office-spreadsheet.png"
#define ASTEROID_ASSET	"assets/images/process-stop.png"
#define BULLET_0        "assets/images/zero.png"
#define BULLET_1        "assets/images/one.png"

#define ERROR 1

/* Stores game textures */
struct Textures {
    SDL_Texture *player;
    SDL_Texture *enemy;
    SDL_Texture *asteroid;
    SDL_Texture *bullet_zero;
    SDL_Texture *bullet_one;
};

int create_texture(SDL_Renderer **renderer, SDL_Texture **texture, char *image_path);
void destroy_texture(SDL_Texture **texture);

#endif
