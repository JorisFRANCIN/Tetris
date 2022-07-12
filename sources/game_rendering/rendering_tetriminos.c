/*
** EPITECH PROJECT, 2022
** rendering_tetriminos
** File description:
** Display the tetriminos falling in the game
*/

#include "tetris.h"

game_t *insert_tetrimino(game_t *game_content, int r)
{
    for (int i = 0; i != game_content->tetriminos[r].size; i++) {
        for (int j = 0; j != game_content->tetriminos[r].size; j++) {
            game_content->map[i][j] =
                game_content->tetriminos[r].tetrimino[i][j];
            game_content->current_tetrimino[i][j] = (position_t){i, j};
        }
        game_content->current_tetrimino
            [game_content->tetriminos[r].size] = NULL;
    }
    return game_content;
}

int rendering_tetriminos(game_t *game_content, int r)
{
    game_content->current_tetrimino = malloc(
        sizeof(position_t *) * game_content->tetriminos[r].size + 1);
    for (int i = 0; i != game_content->tetriminos[r].size; i++)
        game_content->current_tetrimino[i] = malloc(
            sizeof(position_t) * game_content->tetriminos[r].size);
    insert_tetrimino(game_content, r);
    return r;
}
