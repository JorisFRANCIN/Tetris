/*
** EPITECH PROJECT, 2022
** rotate_matrix
** File description:
** rotate either left or right the matrix
*/

#include "tetris.h"

char **cp_tetris(game_t *content, int size)
{
    char **new_tetris = malloc(sizeof(char *) * size);
    for (int i = 0; i != size; i++) {
        new_tetris[i] = malloc(sizeof(char ) * size);
        for (int j = 0; j != size; j++) {
            int pos_x = content->current_tetrimino[i][j].x;
            int pos_y = content->current_tetrimino[i][j].y;
            new_tetris[i][j] = content->map[pos_y][pos_x];
        }
    }
    return new_tetris;
}

char **rotate_left(char **matrix, int size)
{
    for (int i = 0; i != size / 2; i++) {
        for (int j = i; j != size - i - 1; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[size - 1 - j][i];
            matrix[size - 1 - j][i] = matrix[size - 1 - i][size - 1 - j];
            matrix[size - 1 - i][size - 1 - j] = matrix[j][size - 1 - i];
            matrix[j][size - 1 - i] = tmp;
        }
    }
    return matrix;
}

game_t *turn_matrix(game_t *content)
{
    int n = content->index_tetrimino;
    int tmp_size = content->tetriminos[n].height;
    content->tetriminos[n].height = content->tetriminos[n].width;
    content->tetriminos[n].width = tmp_size;
    int size = content->tetriminos[n].size;
    char **cp_matrix = cp_tetris(content, size);
    cp_matrix = rotate_left(cp_matrix, size);
    int pos_x = content->current_tetrimino[0][0].x;
    int pos_y = content->current_tetrimino[0][0].y;

    for (int i = pos_y;  i < pos_y + size; i++) {
        for (int j = pos_x;  j < pos_x + size; j++) {
            content->map[i][j] = cp_matrix[i - pos_y][j - pos_x];
        }
    }
    free(cp_matrix);
    return content;
}
