#include "game_view.h"

#include <fxcg/display.h>
#include <fxcg/misc.h>
#include <stdio.h>
#include <stdlib.h>

#include "../logic/default_logic.h"
#include "../misc.h"

unsigned char cell_height;
unsigned char cell_width;

void init_draw_settings(Game *g) {
    // TODO: eventually make cells squares, find the minimum size and make it a square, or make h/w
    // ratio constant only allowing zoom
    cell_width = (GAME_AREA_END_X - GAME_AREA_START_X) / g->width;
    cell_height = (GAME_AREA_END_Y - GAME_AREA_START_Y) / g->height;
}

void draw_game(Game *g) {
    for (unsigned char y = 0; y < g->height; y++) {
        for (unsigned char x = 0; x < g->width; x++) {
            Bdisp_FilledRectangle(x * cell_width, y * cell_height, (x + 1) * cell_width,
                                  (y + 1) * cell_height,
                                  g->matrix[y][x] ? ALIVE_CELL_COLOR : DEAD_CELL_COLOR);
        }
    }
    Bdisp_PutDisp_DD();
}

#ifdef DEBUG
void dbg_print_neighbours(Game *g) {
    unsigned char **neighbours = malloc(sizeof(unsigned char *) * g->height);
    for (unsigned char i = 0; i < g->height; i++) {
        neighbours[i] = malloc(g->width * sizeof(unsigned char));
        for (int j = 0; j < g->width; j++) {
            neighbours[i][j] = 0;
        }
    }
    compute_neighbours(g, neighbours);

    for (int i = 0; i < g->height; i++) {
        for (int j = 0; j < g->width; j++) {
            unsigned char n[] = "0\0";
            n[0] += neighbours[i][j];
            int x = j * cell_width;
            int y = i * cell_height;
            PrintMiniMini(&x, &y, (char *)n, 0, TEXT_COLOR_RED, 0);
        }
    }
}

void dbg_print_where(Game *g) {
    unsigned char **neighbours = malloc(sizeof(unsigned char *) * g->height);
    for (unsigned char i = 0; i < g->height; i++) {
        neighbours[i] = malloc(g->width * sizeof(unsigned char));
        for (int j = 0; j < g->width; j++) {
            neighbours[i][j] = 0;
        }
    }

    for (unsigned char y = 0; y < g->height; y++) {
        for (unsigned char x = 0; x < g->width; x++) {
            if (g->matrix[y - 1][x - 1]) {
                neighbours[y][x] += 1;
            }
            if (g->matrix[y - 1][x]) {
                neighbours[y][x] += 2;
            }
            if (g->matrix[y - 1][x + 1]) {
                neighbours[y][x] += 4;
            }
            if (g->matrix[y][x - 1]) {
                neighbours[y][x] += 8;
            }
            if (g->matrix[y][x + 1]) {
                neighbours[y][x] += 16;
            }
            if (g->matrix[y + 1][x - 1]) {
                neighbours[y][x] += 32;
            }
            if (g->matrix[y + 1][x]) {
                neighbours[y][x] += 64;
            }
            if (g->matrix[y + 1][x + 1]) {
                neighbours[y][x] += 128;
            }
            char n[3] = "00\0";
            int xc = x * cell_width;
            int yc = y * cell_height;

            uchar_to_hex(neighbours[y][x], n);

            PrintMiniMini(&xc, &yc, n, 0, TEXT_COLOR_RED, 0);
        }
    }
    for (int i = 0; i < g->height; i++) {
        for (int j = 0; j < g->width; j++) {
        }
    }
}
#endif
