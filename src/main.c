/*
 * main.c
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
#include "game.h"
#include "main.h"

int
main(int argc, char* argv[])
{
    extern SDL_Resources core;
    GameData game;

    if(SDL_InitResources(&core) != ERROR) {
        printf("[STATUS] Launching the game...\n");
        GameInit(&game);
        while(KeyboardHandler() != SDL_QUIT) {
            GameRun(&game);
        }
    }

    printf("[STATUS] Exiting the game...\n");
    SDL_CleanResources(&core);

    return 0;
}
