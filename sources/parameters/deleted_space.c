/*
** EPITECH PROJECT, 2022
** delete_space
** File description:
** delete space in a tetrimino
*/

#include "tetris.h"

char **delete_space_tetris(char **file_content)
{
    int j = 0;
    for (int i = 1; file_content[i] != NULL; i++) {
        for (j = my_strlen(file_content[i]) - 1;
            file_content[i][j] == 32; j--) {
            file_content[i][j] = '\0';
        }
    }
    return file_content;
}
