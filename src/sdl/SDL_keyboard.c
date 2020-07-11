/*
 * SDL_keyboard.c
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

#include "SDL_keyboard.h"

struct KeyboardInput key_pressed;

void KeyboardInit()
{
    extern struct KeyboardInput key_pressed;

    key_pressed.up = false;
    key_pressed.down = false;
    key_pressed.left = false;
    key_pressed.right = false;
    key_pressed.enter = false;
    key_pressed.pause = false;
    key_pressed.space = false;
}

int KeyboardHandler(void)
{
    extern struct KeyboardInput key_pressed;

    SDL_Event event;
    event.type = SDL_FIRSTEVENT;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.scancode) {
			case SDL_SCANCODE_ESCAPE:
				event.type = SDL_QUIT;
				break;
            case SDL_SCANCODE_W:
            case SDL_SCANCODE_UP:
                key_pressed.up = true;
                break;
            case SDL_SCANCODE_A:
            case SDL_SCANCODE_LEFT:
                key_pressed.left = true;
                break;
            case SDL_SCANCODE_S:
            case SDL_SCANCODE_DOWN:
                key_pressed.down = true;
                break;
            case SDL_SCANCODE_D:
            case SDL_SCANCODE_RIGHT:
                key_pressed.right = true;
                break;
            case SDL_SCANCODE_RETURN:
				key_pressed.enter = true;
				break;
			case SDL_SCANCODE_SPACE:
				key_pressed.space = true;
				break;
            case SDL_SCANCODE_P:
				key_pressed.pause = true;
				break;
            default:
                break;
            }

            PrintKeyInfo(&event.key);
            break;

        case SDL_KEYUP:
            switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_W:
            case SDL_SCANCODE_UP:
                key_pressed.up = false;
                break;
            case SDL_SCANCODE_A:
            case SDL_SCANCODE_LEFT:
                key_pressed.left = false;
                break;
            case SDL_SCANCODE_S:
            case SDL_SCANCODE_DOWN:
                key_pressed.down = false;
                break;
            case SDL_SCANCODE_D:
            case SDL_SCANCODE_RIGHT:
                key_pressed.right = false;
                break;
            case SDL_SCANCODE_RETURN:
				key_pressed.enter = false;
				break;
			case SDL_SCANCODE_SPACE:
				key_pressed.space = false;
				break;
			case SDL_SCANCODE_P:
				key_pressed.pause = false;
				break;
            default:
                break;
            }
            PrintKeyInfo(&event.key);
            break;

        default:
            break;
        }
    }

    if (event.type == SDL_QUIT) {
		printf("[EVENT] SDL_QUIT event requested.\n");
        return SDL_QUIT;
    }

    else return 0;
}

/* Prints the information about pressed keys */
void PrintKeyInfo(SDL_KeyboardEvent *key)
{
	printf("[KEYBOARD] ");
    if(key->type == SDL_KEYUP) {
        printf("KEY RELEASED: " );
    }

    else {
        printf("KEY PRESSED: ");
    }

    /* Print the hardware scancode */
    printf("Scancode: 0x%02X", key->keysym.scancode);

    printf(", Name: %s", SDL_GetKeyName( key->keysym.sym ));

    PrintModifiers(key->keysym.mod);
    printf("\n" );
}

void PrintModifiers(SDL_Keymod mod)
{
    printf(", Modifers: ");

    /* If there are none then say so and return */
    if(mod == KMOD_NONE) {
        printf("None");
        return;
    }

    if(mod & KMOD_NUM) printf("NUMLOCK ");
    if(mod & KMOD_CAPS) printf("CAPSLOCK ");
    if(mod & KMOD_LCTRL) printf("LCTRL ");
    if(mod & KMOD_RCTRL) printf("RCTRL ");
    if(mod & KMOD_RSHIFT) printf("RSHIFT ");
    if(mod & KMOD_LSHIFT) printf("LSHIFT ");
    if(mod & KMOD_RALT) printf("RALT ");
    if(mod & KMOD_LALT) printf("LALT ");
    if(mod & KMOD_CTRL) printf("CTRL ");
    if(mod & KMOD_SHIFT) printf("SHIFT ");
    if(mod & KMOD_ALT) printf("ALT ");
}
