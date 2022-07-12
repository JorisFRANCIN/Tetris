/*
** EPITECH PROJECT, 2022
** free_all
** File description:
** free all structures
*/

#include "tetris.h"

void free_all(settings_t *settings, game_t *game_content)
{
    new_high_score(game_content);
    int tmp = game_content->nb_tetriminos;
    for (int i = 0; i != tmp; i++) {
        free(game_content->tetriminos[i].tetrimino);
    }
    free(game_content->current_tetrimino);
    free(game_content->map);
    free(game_content->tetriminos);
    free(game_content);
    free(settings);
}
