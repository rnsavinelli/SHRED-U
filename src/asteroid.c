/*
 * asteroid.c
 *
 * Copyright 2020 Roberto Nicolás Savinelli <rnsavinelli@est.frba.utn.edu.ar>
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
 
#include <stdlib.h>

#include "SDL_handler.h"
#include "asteroid.h"

void AsteroidsInit(int window_width, int window_height, struct Asteroid *asteroid)
{
	extern SDL_Resources core;	
	
    for(int i = 0; i < N_ASTEROIDS; i++) {
		asteroid[i].position.x = (rand() % (window_width/2) + (window_width/4));
		asteroid[i].position.y = -(((i+1) * window_height)/N_ASTEROIDS);
		
		SDL_QueryTexture(core.textures.asteroid, NULL, NULL, 
						&(asteroid[i].position.w), 
						&(asteroid[i].position.h));
	}
}

void Asteroids(int window_width, int window_height, struct Asteroid *asteroid)
{
	extern SDL_Resources core;
	
    for(int i = 0; i < N_ASTEROIDS; i++) {
        asteroid[i].position.y += ASTEROID_SPEED/100;

        if(asteroid[i].position.y > window_height + asteroid[i].position.w) {
			(asteroid[i]).position.x = rand() % (window_width/2 - asteroid[i].position.w) 
										+ (window_width/4) + asteroid[i].position.w/2;
            (asteroid[i]).position.y = - asteroid[i].position.h;
        }
 
		SDL_RenderCopy(core.renderer, core.textures.asteroid, 
						NULL, &(asteroid[i].position));						
    }
}
