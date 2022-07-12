/*
** EPITECH PROJECT, 2022
** keep_data
** File description:
** retrieve the old score
*/

#include "tetris.h"

int retrieve_data(game_t *content)
{
    int fd = open("high_score.legend", O_RDWR);
    if (fd == -1)
        return 0;
    struct stat id;
    stat("high_score.legend", &id);
    if (id.st_size == 0)
        return 0;
    char buff[id.st_size];
    read(fd, buff, id.st_size);
    content->high_score = my_atoi(buff);
    close(fd);

    return 0;
}

int new_high_score(game_t *content)
{
    int fd = open("high_score.legend", O_RDWR);
    int len = my_strlen(nbr_to_str(content->high_score));
    write(fd, nbr_to_str(content->high_score), len);
    close(fd);

    return 0;
}

int keep_data(game_t *content)
{
    if (content->high_score <= content->score) {
        return content->score;
    }
    return content->high_score;
}
