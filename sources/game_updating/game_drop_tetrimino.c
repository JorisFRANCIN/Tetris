/*
** EPITECH PROJECT, 2022
** game_drop_tetrimino
** File description:
** drop the tetrimino
*/

#include "tetris.h"

void game_drop_tetrimino(game_t *game_content, settings_t *settings, int key)
{
    if (key == settings->drop) {
        while (game_content->current_tetrimino[0][0].y +
            game_content->tetriminos[game_content->index_tetrimino].height <
            game_content->settings->map_size.rows &&
            is_blocked(game_content) < 1)
            falling_rules(game_content);
    }
}
