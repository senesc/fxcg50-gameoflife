// This code is ugly and slow, but we need to implement some logic demo.
#include "default_logic.h"

#include <stdbool.h>
#include <stdlib.h>

Game *setup_game(unsigned char height, unsigned char width) {

    Game *g = malloc(sizeof(Game));
    g->width = width;
    g->height = height;

    g->matrix = malloc((height + 2) * sizeof(unsigned char *));
    // we want the game matrix to be padded for easier calculations.
    // but we set the pointers to act as it was not.
    for (unsigned char y = 0; y < height + 2; y++) {
        g->matrix[y] = malloc((width + 2) * sizeof(unsigned char));
        for (unsigned char x = 0; x < width + 2; x++) {
            g->matrix[y][x] = false;
        }
        g->matrix[y] += 1;
    }
    g->matrix += 1;
    return g;
}

void destroy_game(Game *g) { // FIXME:
    for (short i = -1; i <= g->height; i++) {
        free(g->matrix[i]);
    }
    free(g->matrix);
    free(g);
}

// void compute_neighbours(Game *g, unsigned char **neighbours) {
//     for (unsigned char y = 0; y < g->height; y++) {
//         for (unsigned char x = 0; x < g->width; x++) {
//             neighbours[y][x] =
//                 (unsigned char)g->matrix[y - 1][x - 1] + (unsigned char)g->matrix[y - 1][x] +
//                 (unsigned char)g->matrix[y - 1][x + 1] + (unsigned char)g->matrix[y][x - 1] +
//                 (unsigned char)g->matrix[y][x + 1] + (unsigned char)g->matrix[y + 1][x - 1] +
//                 (unsigned char)g->matrix[y - 1][x] + (unsigned char)g->matrix[y + 1][x + 1];
//         }
//     }
// }
void compute_neighbours(Game *g, unsigned char **neighbours) {
    for (unsigned char y = 0; y < g->height; y++) {
        for (unsigned char x = 0; x < g->width; x++) {
            neighbours[y][x] = g->matrix[y - 1][x - 1] + g->matrix[y - 1][x] +
                               g->matrix[y - 1][x + 1] + g->matrix[y][x - 1] + g->matrix[y][x + 1] +
                               g->matrix[y + 1][x - 1] + g->matrix[y + 1][x] +
                               g->matrix[y + 1][x + 1];
        }
    }
}

void game_advance(Game *g) {
    unsigned char **neighbours = malloc(sizeof(unsigned char *) * g->height);
    for (unsigned char i = 0; i < g->height; i++) {
        neighbours[i] = malloc(g->width * sizeof(unsigned char));
    }
    compute_neighbours(g, neighbours);
    for (unsigned char y = 0; y < g->height; y++) {
        for (unsigned char x = 0; x < g->width; x++) {
            if (neighbours[y][x] > 3 || neighbours[y][x] < 2) {
                g->matrix[y][x] = false;
            } else if (neighbours[y][x] == 3) {
                g->matrix[y][x] = true;
            }
            // nothing to do if there are 2 neighbours.
        }
    }
}
