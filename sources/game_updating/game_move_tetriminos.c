/*
** EPITECH PROJECT, 2022
** game_ctrl
** File description:
** Managing the ctrls of the tetrimino
*/

#include "tetris.h"

game_t *change_pos(game_t *content, int x)
{
    int n = content->index_tetrimino;
    int height = content->tetriminos[n].height;
    int width = content->tetriminos[n].width;
    for (int i = 0; i != height; i++) {
        for (int j = 0; j != width; j++)
            content->current_tetrimino[i][j].x += x;
    }

    return content;
}

int move_tetri_l(game_t *content)
{
    int n = content->index_tetrimino;
    int height = content->tetriminos[n].height;
    int width = content->tetriminos[n].width;
    if (content->current_tetrimino[0][0].x < 0)
        return 1;
    for (int i = 0 + content->current_tetrimino[0][0].y;
        i != content->current_tetrimino[0][0].y + height; i++) {
        for (int j = content->current_tetrimino[0][0].x;
            j != content->current_tetrimino[0][0].x + width; j++) {
            content->map[i][j] == '*' && content->map[i][j - 1] == ' ' ?
                swap_array_element(content, (position_t){i, j},
                    (position_t){i, j - 1}) : 0;
        }
    }
    return 0;
}

int move_tetri_r(game_t *content)
{
    int n = content->index_tetrimino;
    int height = content->tetriminos[n].height;
    int width = content->tetriminos[n].width;
    if (content->current_tetrimino[0][0].x + width >=
        content->settings->map_size.columns)
        return 1;
    for (int i = 0 + content->current_tetrimino[0][0].y;
        i != content->current_tetrimino[0][0].y + height; i++) {
        for (int j = content->current_tetrimino[0][0].x + width;
            j != content->current_tetrimino[0][0].x; j--) {
            content->map[i][j - 1] == '*' ?
                swap_array_element(content, (position_t){i, j},
                    (position_t){i, j - 1}) : 0;
        }
    }
    return 0;
}

void game_move_tetriminos(game_t *content, settings_t *settings, int key)
{
    int n = content->index_tetrimino;
    int height = content->tetriminos[n].height;
    int width = content->tetriminos[n].width;
    if (key == settings->mv_right && is_blocked(content) < 1 &&
        content->current_tetrimino[0][0].x + width <
            settings->map_size.columns) {
        move_tetri_r(content) == 0 ? change_pos(content, 1) : 0;
    } else if (key == settings->mv_left && is_blocked(content) < 1 &&
        content->current_tetrimino[height - 1][0].x > 0) {
        move_tetri_l(content) == 0 ? change_pos(content, -1) : 0;
    }
    if (key == settings->pause) {
        content->pause = 1;
        usleep(10000000);
        content->pause = 0;
    }
    game_drop_tetrimino(content, settings, key);
    game_turn_tetriminos(content, settings, key);
}
