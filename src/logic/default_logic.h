#ifndef _DEFAULT_LOGIC_H
#define _DEFAULT_LOGIC_H

#include <stdbool.h>

typedef struct {
    unsigned char height;
    unsigned char width;
    unsigned char **matrix;
} Game;

extern Game *setup_game(unsigned char height, unsigned char width);
extern void destroy_game(Game *game);
extern void game_advance(Game *game);
extern void compute_neighbours(Game *game, unsigned char **neighbours);

#endif
