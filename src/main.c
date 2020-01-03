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

int main(int argc, char** argv)
{
    extern SDL_Resources core;
    GameData game;
	int status = 0;

    if(SDL_InitResources(&core) != ERROR) {
		printf("Launching game...\n");
        GameInit(&game);
        while(status != SDL_QUIT) {
			status = KeyboardHandler();
            GameRun(&game);
        }
    }
	
	printf("Quitting the game...\n");
    /* game_quit(&game); */
    SDL_CleanResources(&core);

    return 0;
}
