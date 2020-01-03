/*
 * game.c
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
#include "collisions.h"

/* Initializes game variables */
void GameInit(GameData *game)
{	
	game->menu = MENU_GAME_START;

	PlayerInit(&(game->player));
	
	for(int i = 0; i < N_ENEMIES; i++) {
		EnemyInit(&(game->enemy[i]));
	}
	
	for(int i = 0; i < N_ASTEROIDS; i++) {
		AsteroidInit(&(game->asteroid[i]));
	}
}

void GameRun(GameData *game)
{
	extern SDL_Resources core;
	
	switch(game->menu) {
		case MENU_MAIN_MENU:
			GameMainMenu();
			break;
		case MENU_GAME_START:
			GameStart(game);
			break;
		case MENU_GAME_RESTART:
			GameRestart();
			break;
		case MENU_GAME_OVER:
			GameOver();
			break;
		case MENU_INSERT_NAME:
			GameSave();
			break;
		case MENU_GAME_SCORES:
			GameScores();
			break;
		default:
			break;
	}

    SDL_RenderClear(core.renderer);

	SDL_RenderCopy(core.renderer, core.textures.player, NULL, &(game->player.position));

	SDL_RenderPresent(core.renderer);
	SDL_Delay(1000/60);
}

void GameMainMenu(){}

void GameStart(GameData *game) {
	PlayerMovement(&(game->player));
	BoundDetection(WINDOW_WIDTH, WINDOW_HEIGHT, game);
}

void GameRestart(){}
void GameOver(){}
void GameSave(){}
void GameScores(){}

void GameQuit(GameData *game)
{

}
