/*
** EPITECH PROJECT, 2022
** open_tetriminos
** File description:
** open the .tetriminos file
*/

#include "tetris.h"

char *open_tetriminos(char *name)
{
    int fd = open(my_strcat("tetriminos/", name), O_RDONLY);
    struct stat id;
    stat(my_strcat("tetriminos/", name), &id);
    char *buff = malloc(id.st_size);
    read(fd, buff, id.st_size);
    close(fd);
    return buff;
}
