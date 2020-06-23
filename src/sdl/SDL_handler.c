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

SDL_Resources core;

/* Initializes all core functions needed for the game to run */
int SDL_InitResources(SDL_Resources *sdl)
{
    printf("[STATUS] Initializing SDL subsystems...\n");

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("[WARNING] Error initializing SDL: %s\n", SDL_GetError());
        return ERROR;
    }

    printf("[STATUS] Creating window...\n");

    if(create_window(&(sdl->window)) == ERROR ) {
        printf("[WARNING] Failed to create the window: %s\n", SDL_GetError());
        return ERROR ;
    }

    printf("[STATUS] Creating renderer...\n");

    if(create_renderer(&(sdl->renderer), &(sdl->window)) == ERROR) {
        printf("[WARNING] Failed to create the renderer: %s\n", SDL_GetError());
        return ERROR;
    }

    printf("[STATUS] Creating textures...\n");

    if(create_texture(&(sdl->renderer), &(sdl->textures.player), PLAYER_ASSET) == ERROR) {
        return ERROR;
    }

    if(create_texture(&(sdl->renderer), &(sdl->textures.enemy), ENEMY_ASSET) == ERROR) {
        return ERROR;
    }

    if(create_texture(&(sdl->renderer), &(sdl->textures.asteroid), ASTEROID_ASSET) == ERROR) {
        return ERROR;
    }

    if(create_texture(&(sdl->renderer), &(sdl->textures.bullet_zero), BULLET_0) == ERROR) {
        return ERROR;
    }

    if(create_texture(&(sdl->renderer), &(sdl->textures.bullet_one), BULLET_1) == ERROR) {
        return ERROR;
    }

    printf("[STATUS] Initializing keyboard...\n");
    KeyboardInit();

    printf("[STATUS] Initializing TTF...\n");

    if (TTF_Init() != 0) {
        printf("[WARNING] Failed to initialize TTF: %s\n", SDL_GetError());
        return ERROR;
    }

    printf("[STATUS] Loading fonts...\n");

    sdl->fonts.title = TTF_OpenFont(TITLE_FONT_PATH, 40);
    if (sdl->fonts.title == NULL) {
        printf("[WARNING] Failed to load font: %s\n",TTF_GetError());
        return ERROR;
    }

    sdl->fonts.text = TTF_OpenFont(TEXT_FONT_PATH, 24);
    if (sdl->fonts.text == NULL) {
        printf("[WARNING] Failed to load font: %s\n",TTF_GetError());
        return ERROR;
    }

    printf("[STATUS] All resources were initialized.\n");

    return 0;
}

/* Cleans all used resources */
void SDL_CleanResources(SDL_Resources *sdl)
{
    if(sdl->textures.player != NULL || sdl->textures.enemy != NULL || sdl->textures.asteroid != NULL
        || sdl->textures.bullet_zero != NULL || sdl->textures.bullet_one != NULL) {
        printf("[STATUS] Destroying textures...\n");
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

    if(sdl->textures.bullet_zero != NULL) {
        SDL_DestroyTexture(sdl->textures.bullet_zero);
    }

    if(sdl->textures.bullet_one != NULL) {
        SDL_DestroyTexture(sdl->textures.bullet_one);
    }

    printf("[STATUS] Terminating TTF API...\n");
    TTF_Quit();

    if(sdl->renderer != NULL) {
        printf("[STATUS] Destroying renderer...\n");
        SDL_DestroyRenderer(sdl->renderer);
    }

    if(sdl->window != NULL) {
        printf("[STATUS] Destroying window...\n");
        SDL_DestroyWindow(sdl->window);
    }

    SDL_Quit();

    printf("[STATUS] All initialized SDL subsystems were cleaned up.\n");
}
