/*
** EPITECH PROJECT, 2022
** can_go_there
** File description:
** verify if the current tetrimino can go this direction
*/

#include "tetris.h"

int can_go_right(game_t *content)
{
    int n = content->index_tetrimino;
    int height = content->tetriminos[n].height;
    int width = content->tetriminos[n].width;
    int check = 0;
    int pos_x = content->current_tetrimino[0][0].x + width - 1;
    if (pos_x == content->settings->map_size.columns)
        return 1;
    for (int i = content->current_tetrimino[0][0].y;
        i != content->current_tetrimino[0][0].y + height; i++) {
        check += content->map[i][width] == ' ' ? 0 : 1;
    }
    return check;
}

int can_go_left(game_t *content)
{
    int n = content->index_tetrimino;
    int height = content->tetriminos[n].height;
    int check = 0;
    int pos_x = content->current_tetrimino[0][0].x;
    if (pos_x <= 0)
        return 1;
    for (int i = content->current_tetrimino[0][0].y;
        i != content->current_tetrimino[0][0].y + height; i++) {
        check += content->map[i][pos_x - 1] == ' ' ? 0 : 1;
    }
    return check;
}
