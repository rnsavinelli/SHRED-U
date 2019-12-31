/*
 * SDL_handler.c
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

#include "SDL_handler.h"
#include "SDL_window.h"
#include "SDL_textures.h"
#include "SDL_fonts.h"

/* Initializes all core functions needed for the game to run */
int SDL_init_resources(struct Resources *sdl)
{
    printf("Initializing SDL subsystems...\n");

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        return ERROR;
    }

    printf("Initializing TTF...\n");

    if (TTF_Init() != 0) {
        printf("Failed to initialize TTF: %s\n", SDL_GetError());
        return ERROR;
    }

    printf("Loading fonts...\n");

    sdl->fonts.title = TTF_OpenFont(TITLE_FONT_PATH, 18);
    if (sdl->fonts.title == NULL) {
        printf("Failed to load font: %s\n",TTF_GetError());
        return ERROR;
    }

    sdl->fonts.text = TTF_OpenFont(TEXT_FONT_PATH, 12);
    if (sdl->fonts.text == NULL) {
        printf("Failed to load font: %s\n",TTF_GetError());
        return ERROR;
    }

    printf("Creating window...\n");

    if(create_window(&(sdl->window)) == ERROR ) {
        printf("Failed to create the window: %s\n", SDL_GetError());
        return ERROR ;
    }

    printf("Creating renderer...\n");

    if(create_renderer(&(sdl->renderer), &(sdl->window)) == ERROR) {
        printf("Failed to create the renderer: %s\n", SDL_GetError());
        return ERROR;
    }

    printf("Creating textures...\n");

    if(create_texture(&(sdl->renderer), &(sdl->textures.player), PLAYER_ASSET) == ERROR) {
        return ERROR;
    }

    if(create_texture(&(sdl->renderer), &(sdl->textures.enemy), ENEMY_ASSET) == ERROR) {
        return ERROR;
    }

    if(create_texture(&(sdl->renderer), &(sdl->textures.asteroid), ASTEROID_ASSET) == ERROR) {
        return ERROR;
    }

    return 0;
}

/* Cleans all used resources */
void SDL_clean_resources(struct Resources *sdl)
{
    if(sdl->renderer != NULL) {
        SDL_DestroyRenderer(sdl->renderer);
    }

    if(sdl->window != NULL) {
        SDL_DestroyWindow(sdl->window);
    }

    if(sdl->textures.player != NULL) {
        SDL_DestroyTexture(sdl->textures.player);
    }

    if(sdl->textures.enemy != NULL) {
        SDL_DestroyTexture(sdl->textures.enemy);
    }

    if(sdl->textures.asteroid != NULL) {
        SDL_DestroyTexture(sdl->textures.asteroid);
    }

    TTF_Quit();

    SDL_Quit();

    printf("All initialized SDL subsystems were cleaned up.\n");
}
