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

/* Initializes game variables */
void game_init(struct Resources *core, struct Game *data)
{
    /* Default values */
    data->player.status = 0;
    data->player.score = 0;
    data->player.hp = 3;
    data->menu = MENU_MAIN_MENU;

    /* Player's position */
    SDL_QueryTexture(core->textures.player, NULL, NULL, &(data->player.position.w), &(data->player.position.h));
    data->player.position.x = (WINDOW_WIDTH - data->player.position.w) / 2;
    data->player.position.y = (WINDOW_HEIGHT - data->player.position.h);

    data->player.speed.x = DEFAULT_SPEED;
    data->player.speed.y = DEFAULT_SPEED;

    
}

void game_run(struct Resources *core, struct Game*data)
{
    bool close_window = false;

    int up = 0;
    int down = 0;
    int left = 0;
    int right = 0;

    while (close_window != true) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                printf("SDL_QUIT event successfully requested.\n");
                close_window = true;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_W:
                case SDL_SCANCODE_UP:
                    up = 1;
                    break;
                case SDL_SCANCODE_A:
                case SDL_SCANCODE_LEFT:
                    left = 1;
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    down = 1;
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    right = 1;
                    break;
                default:
                    break;
                }
                break;
                
            case SDL_KEYUP:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_W:
                case SDL_SCANCODE_UP:
                    up = 0;
                    break;
                case SDL_SCANCODE_A:
                case SDL_SCANCODE_LEFT:
                    left = 0;
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    down = 0;
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    right = 0;
                    break;
                default:
                    break;
                }
                break;
           default:
                break;
            }

        }

        data->player.speed.x = data->player.speed.y = 0;

        if (up == 1 && down == 0) 
        {
            data->player.speed.y = DEFAULT_SPEED;
        }

        if (down == 1 && up == 0)
        {
            data->player.speed.y = -3*(DEFAULT_SPEED/4);
        }

        if (left == 1 && right == 0)
        {
            data->player.speed.x = -DEFAULT_SPEED;
        }

        if (right == 1 && left == 0)
        {
            data->player.speed.x = DEFAULT_SPEED;
        }

        if (data->player.position.x <= 0) data->player.position.x = 0;
        if (data->player.position.y <= 0) data->player.position.y = 0;
        if (data->player.position.x >= WINDOW_WIDTH - data->player.position.w) data->player.position.x = WINDOW_WIDTH - data->player.position.w;
        if (data->player.position.y >= WINDOW_HEIGHT - data->player.position.h) data->player.position.y = WINDOW_HEIGHT - data->player.position.h;

        data->player.position.x += (int) data->player.speed.x/100;
        data->player.position.y -= (int) data->player.speed.y/100;

        SDL_RenderClear(core->renderer);

        SDL_RenderCopy(core->renderer, core->textures.player, NULL, &(data->player.position));

        SDL_RenderPresent(core->renderer);
        SDL_Delay(1000/60);
    }
}

void game_quit(struct Game *data)
{

}
