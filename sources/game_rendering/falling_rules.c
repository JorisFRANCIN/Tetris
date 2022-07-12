/*
** EPITECH PROJECT, 2022
** falling_rules
** File description:
** apply the falling effect for the tetrimino
*/

#include "tetris.h"

int is_not_in_hitbox(game_t *game_content, int y, int x)
{
    int n = game_content->index_tetrimino;
    int height = game_content->tetriminos[n].height;
    int width = game_content->tetriminos[n].width;
    int check = 0;
    for (int i = 0; i != height; i++) {
        for (int j = 0; j != width; j++) {
            check += y == game_content->current_tetrimino[i][j].y &&
                x == game_content->current_tetrimino[i][j].x &&
                game_content->map[y][x] != ' ' ? 1 : 0;
        }
    }
    return check;
}

int verify_hitbox(game_t *game_content, int y, int x)
{
    if (game_content->map[y][x] == '*' &&
        is_not_in_hitbox(game_content, y, x) == 0)
        return 1;
    return 0;
}

game_t *swap_array_element(game_t *game_content, position_t pos1,
    position_t pos2
)
{
    int i = pos1.y;
    int j = pos1.x;
    int i2 = pos2.y;
    int j2 = pos2.x;
    char tmp = game_content->map[i][j];
    game_content->map[i][j] = game_content->map[i2][j2];
    game_content->map[i2][j2] = tmp;

    return game_content;
}

int is_blocked(game_t *game_content)
{
    int n = game_content->index_tetrimino;
    int height = game_content->tetriminos[n].height;
    int width = game_content->tetriminos[n].width;
    int check = 0;
    for (int i = 0; i != height; i++) {
        for (int j = 0; j != width; j++) {
            int y = game_content->current_tetrimino[i][j].y;
            int x = game_content->current_tetrimino[i][j].x;
            check += game_content->map[y][x] == '*' &&
                verify_hitbox(game_content, y + 1, x) == 1 ? 1 : 0;
        }
    }
    return check;
}

int falling_rules(game_t *game_content)
{
    int n = game_content->index_tetrimino;
    int height = game_content->tetriminos[n].height;
    int width = game_content->tetriminos[n].width;
    for (int i = game_content->current_tetrimino[0][0].y + height;
        i > game_content->current_tetrimino[0][0].y; i--) {
        for (int j = game_content->current_tetrimino[0][0].x;
            j != game_content->current_tetrimino[0][0].x + width; j++) {
            game_content->map[i - 1][j] == '*' ?
                swap_array_element(game_content, (position_t){i, j},
                    (position_t){i - 1, j}) : 0;
        }
    }
    for (int i = 0; i != height; i++) {
        for (int j = 0; j != width; j++)
            game_content->current_tetrimino[i][j].y += 1;
    }
    return 0;
}
