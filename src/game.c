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

#include <time.h>
#include <stdlib.h>

#include "SDL_handler.h"
#include "game.h"
#include "main.h"

/* Initializes game variables */
void GameInit(GameData *game)
{
    game->menu = MENU_MAIN_MENU;

	srand(time(NULL));

    playerInit(WINDOW_WIDTH, WINDOW_HEIGHT, &(game->player));
    bulletsInit(WINDOW_WIDTH, WINDOW_HEIGHT, &(game->player));
    enemiesInit(WINDOW_WIDTH, WINDOW_HEIGHT, game->enemy);
	asteroidsInit(WINDOW_WIDTH, WINDOW_HEIGHT, game->asteroid);
}

void GameRun(GameData *game)
{
    extern SDL_Resources core;
    extern struct KeyboardInput key_pressed;    

    SDL_RenderClear(core.renderer);

    switch(game->menu) {
    case MENU_MAIN_MENU:
        GameMainMenu();
		if(key_pressed.enter) {
			game->menu = MENU_GAME_START;
		}
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

    SDL_RenderPresent(core.renderer);
    SDL_Delay(1000/60);
}

void GameMainMenu()
{
    extern SDL_Resources core;

	SDL_Color Yellow = {255, 215, 0};
	SDL_Color White = {255, 255, 255};    
    
    SDL_Surface* surfaceText;
	SDL_Texture* Text;
	SDL_Rect Text_rect;

	/* TITLE */
	surfaceText = TTF_RenderText_Solid(core.fonts.title, "SHRED -U", Yellow);
	Text = SDL_CreateTextureFromSurface(core.renderer, surfaceText);
	
	Text_rect.w = surfaceText->w;
	Text_rect.h = surfaceText->h;
	Text_rect.x = WINDOW_WIDTH/2 - surfaceText->w/2;
	Text_rect.y = WINDOW_HEIGHT/4;

	SDL_RenderCopy(core.renderer, Text, NULL, &Text_rect);

	/* Game Start */
	surfaceText = TTF_RenderText_Solid(core.fonts.text, "Press ENTER to start", White);
	Text = SDL_CreateTextureFromSurface(core.renderer, surfaceText);
	
	Text_rect.w = surfaceText->w;
	Text_rect.h = surfaceText->h;
	Text_rect.x = WINDOW_WIDTH/2 - surfaceText->w/2;
	Text_rect.y = WINDOW_HEIGHT/2;

	SDL_RenderCopy(core.renderer, Text, NULL, &Text_rect);
	
	/* Game Quit */
	surfaceText = TTF_RenderText_Solid(core.fonts.text, "Press ESCAPE to exit", White);
	Text = SDL_CreateTextureFromSurface(core.renderer, surfaceText);
	
	Text_rect.w = surfaceText->w;
	Text_rect.h = surfaceText->h;
	Text_rect.x = WINDOW_WIDTH/2 - surfaceText->w/2;
	Text_rect.y = WINDOW_HEIGHT/2 + surfaceText->h*2;

	SDL_RenderCopy(core.renderer, Text, NULL, &Text_rect);

	SDL_FreeSurface(surfaceText);
	SDL_DestroyTexture(Text);	
}

void GameStart(GameData *game)
{
	player(WINDOW_WIDTH, WINDOW_HEIGHT, &(game->player));
    bullets(WINDOW_WIDTH, WINDOW_HEIGHT, &(game->player));
    enemies(WINDOW_WIDTH, WINDOW_HEIGHT, game->enemy);
    asteroids(WINDOW_WIDTH, WINDOW_HEIGHT, game->asteroid);

    BoundDetection(WINDOW_WIDTH, WINDOW_HEIGHT, game);
    CollisionHandler(WINDOW_WIDTH, WINDOW_HEIGHT, game);
}

void GameRestart() {}
void GameOver() {}
void GameSave() {}
void GameScores() {}

void GameQuit(GameData *game)
{

}
