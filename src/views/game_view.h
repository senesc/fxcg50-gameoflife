#ifndef _GAME_VIEW_H
#define _GAME_VIEW_H

#include "../logic/default_logic.h"
// FIXME: onthological error here: this should not depend on a particular logic implementation.
// But first we'd have to know what *all* implementations have in common.
// Could fix by setting height and width as general settings, and then only passing the matrix.

#define GAME_AREA_START_X 0
#define GAME_AREA_START_Y 0
#define GAME_AREA_END_X 383
#define GAME_AREA_END_Y 191

#define ALIVE_CELL_COLOR COLOR_BLACK
#define DEAD_CELL_COLOR COLOR_WHITE

extern unsigned char cell_height;
extern unsigned char cell_width;

extern void draw_game(Game *game);
extern void init_draw_settings(Game *game);

#ifdef DEBUG
extern void dbg_print_neighbours(Game *game);
extern void dbg_print_where(Game *game);
#endif

#endif
