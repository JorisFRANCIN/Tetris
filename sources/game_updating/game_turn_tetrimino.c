/*
** EPITECH PROJECT, 2022
** game_turn_tetrimino
** File description:
** turn the tetrimino
*/

#include "tetris.h"

void game_turn_tetriminos(game_t *content, settings_t *settings, int key)
{
    if (key == settings->turn) {
        turn_matrix(content);
    }
}
