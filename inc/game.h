/*
 * game.h
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

#ifndef GAME_H
#define GAME_H

#include "SDL_handler.h"
#include "player.h"
#include "asteroid.h"
#include "enemy.h"

#define ERROR 1

enum APP_MENU {
    MENU_MAIN_MENU,
    MENU_GAME_START,
    MENU_GAME_RESTART,
    MENU_GAME_OVER,
    MENU_INSERT_NAME,
    MENU_GAME_SCORES
};

typedef struct Game {
    int menu;
    struct Player player;
    struct Enemy enemy[N_ENEMIES];
    struct Asteroid asteroid[N_ASTEROIDS];
}
GameData;

void GameInit(GameData *game);
void GameRun(GameData *game);
void GameQuit(GameData *game);

void GameMainMenu();
void GameStart(GameData *game);
void GameRestart();
void GameOver();
void GameSave();
void GameScores();

#endif
