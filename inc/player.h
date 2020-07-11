/*
 * player.h
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

#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <stdbool.h>

#define N_BULLETS	40

#define DEFAULT_SPEED	500
#define BULLET_SPEED	1200

#define DEFAULT_TOLERANCE	100
#define DEFAULT_HP			3

struct Speed {
    float x;
    float y;
};

struct Bullets {
    bool status;
    SDL_Rect position;
    SDL_Texture *texture;
};

struct Player {
    int tolerance;
    int score;
    int hp;
    SDL_Rect position;
    struct Speed speed;
    struct Bullets bullets[N_BULLETS];
};

void player(int window_width, int window_height, struct Player *player);
void playerInit(int window_width, int window_height, struct Player *player);
void playerBounds(int window_width, int window_height, struct Player *player);
void playerDraw(struct Player *player);

void bullets(int window_width, int window_height, struct Player *player);
void bulletsInit(int window_width, int window_height, struct Player *player);
void bulletsHandler(int window_width, int window_height, struct Player *player);
void bulletsMove(int window_width, int window_height, struct Player *player);
void bulletsBounds(int window_width, int window_height, struct Player *player);
void bulletsDraw(struct Player *player);

#endif
