/*
** EPITECH PROJECT, 2022
** win_condition
** File description:
** if a lines is complete
*/

#include "tetris.h"

game_t *make_fall(game_t *game_content)
{
    for (int i = game_content->settings->map_size.rows - 1; i != 0; i--) {
        for (int j = 0; j != game_content->settings->map_size.columns; j++) {
            game_content->map[i][j] = '*';
            game_content->map[i][j] = game_content->map[i - 1][j];
        }
    }
    for (int j = 0; j != game_content->settings->map_size.columns; j++) {
        game_content->map[0][j] = ' ';
    }
    return game_content;
}

int this_line(game_t *content, int i)
{
    int block = 0;
    for (int j = 0; content->map[i][j] != '\0'; j++) {
        if (content->map[i][j] == '*') {
            block += 1;
        }
    }
    return block;
}

int win_line(game_t *content)
{
    int check_line = 0;
    int valid_line = 0;
    int the_line = 0;
    for (int i = 0; content->map[i] != NULL; i++) {
        check_line = this_line(content, i);
        if (check_line == content->settings->map_size.columns) {
            valid_line = 1;
            the_line = i;
        }
    }
    if (valid_line >= 1) {
        for (int j = 0; content->map[the_line][j] != '\0'; j++)
            content->map[the_line][j] = ' ';
        make_fall(content);
        content->line += 1;
        content->score += 100 * valid_line;
        return 1;
    }
    return 0;
}
