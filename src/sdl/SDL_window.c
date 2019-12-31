/*
 * SDL_window.h
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

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include "SDL_window.h"

/* Creates the window */
int create_window(SDL_Window **window)
{	
    *window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,
							SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH,
							WINDOW_HEIGHT, 0);
	
    /* If something's not ok return SDL_HANDLER_ERROR */							
    if (*window == NULL)
    {
	    return ERROR;
    }
    
    else return 0;

}

/* Creates the renderer */
int create_renderer(SDL_Renderer **renderer, SDL_Window **window)
{
	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

	*renderer = SDL_CreateRenderer(*window, -1, render_flags);
	
    /* If something's not ok return SDL_HANDLER_ERROR */
	if (*renderer == NULL)
	{
        return ERROR;
    }
    
    else
    {
	    SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);
		SDL_RenderClear(*renderer);
		SDL_RenderPresent(*renderer);
		return 0;
	}
}
