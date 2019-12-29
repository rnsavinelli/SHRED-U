#ifndef GAME_HANDLER_H
#define GAME_HANDLER_H

#include "SDL_handler.h"

#define DEFAULT_SPEED 300

struct Speed {
	float x;
	float y;
};

struct Player {
	int status;
	int score;
	int hp;
	SDL_Rect position;
	struct Speed speed;
};

void init_game(struct Resources *core, struct Player *data);
void run_game(struct Resources *core, struct Player *data);
void quit_game(struct Player *data);

#endif
