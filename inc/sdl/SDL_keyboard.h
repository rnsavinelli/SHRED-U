/*
 * SDL_keyboard.h
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

#ifndef SDL_KEYBOARD_H
#define SDL_KEYBOARD_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_keycode.h>

#include <stdbool.h>

struct KeyboardInput {
    bool up;
    bool down;
    bool left;
    bool right;
    bool enter;
    bool pause;
    bool space;
};

void KeyboardInit(void);

int KeyboardHandler(void);
void PrintKeyInfo(SDL_KeyboardEvent *key);
void PrintModifiers(SDL_Keymod mod);

#endif
