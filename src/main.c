#include <fxcg/display.h>
#include <fxcg/keyboard.h>
#include <fxcg/misc.h>
#include <fxcg/system.h>

#include "logic/default_logic.h"
#include "stddef.h"
#include "views/game_view.h"

void setup_sample_matrix(Game *g) {
    g->matrix[0][0] = true;
    g->matrix[3][5] = true;
    g->matrix[4][5] = true;
    g->matrix[5][5] = true;
}

int main(void) {
    int key;

    Bdisp_AllClr_VRAM();
    Game *g = NULL;

    while (1) {
        GetKey(&key);
        if (key == KEY_CTRL_EXIT) {
            break;
        } else if (key == KEY_CTRL_AC) {
            if (g != NULL) {
                destroy_game(g); // FIXME:
            }
            g = setup_game(10, 20);
            init_draw_settings(g);
            setup_sample_matrix(g);
            draw_game(g);
        } else if (key == KEY_CTRL_EXE) {
            if (g != NULL) {
                game_advance(g);
                draw_game(g);
            }
        } else if (key == KEY_CTRL_F1) {
            if (g != NULL) {
                game_advance(g);
            }
        } else if (key == KEY_CTRL_F2) {
            if (g != NULL) {
                draw_game(g);
            }
        }
#ifdef DEBUG
        else if (key == KEY_CTRL_F3) {
            dbg_print_neighbours(g);
        } else if (key == KEY_CTRL_F4) {
            dbg_print_where(g);
        }
#endif
    }

    return 0;
}
