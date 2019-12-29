#ifndef SDL_HANDLER_H
#define SDL_HANDLER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

#define PLAYER_ASSET "resources/images/drive-harddisk.png"
#define ENEMY_ASSET "resources/images/text-x-generic.png"
#define ASTEROID_ASSET "resources/images/dialog-error.png"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

/* For storing game textures */
struct Textures {
	SDL_Texture* player;
	SDL_Texture* enemy;
	SDL_Texture* asteroid;
};

/* SDL resources */
struct Resources {
	SDL_Window* window;
	SDL_Renderer* renderer;
	struct Textures textures;
};

int init_resources(struct Resources *core);

int SDL_init(void);
int create_window(struct Resources *core);
int create_renderer(struct Resources *core);
int create_textures(struct Resources* core, SDL_Texture** texture, char* image_path);

void clean_resources(struct Resources *core);

#endif
