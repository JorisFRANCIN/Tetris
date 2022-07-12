/*
** EPITECH PROJECT, 2022
** is_tetriminos
** File description:
** verify if the tetrimino's format is respected
*/

#include "tetris.h"

int content_message(char *name, int flag)
{
    char *buff = open_tetriminos(name);
    char **file_content = str_to_word_array(buff, '\n');
    char **content_format = str_to_word_array(file_content[0], ' ');

    if (flag == 1) {
        my_printf("Tetriminos '%s': ", file_name(name));
        my_printf("size %d*%d, color %d\n", my_atoi(content_format[0]),
            my_atoi(content_format[1]), my_atoi(content_format[2]));
        delete_space_tetris(file_content);
        for (int i = 1; i <= my_atoi(content_format[1]); i++)
            my_printf("%s\n", file_content[i]);
    } else {
        my_printf("Tetriminos '%s': error\n", file_name(name));
    }
    free(content_format);
    free(file_content);
    return flag == 1 ? 1 : 0;
}

int verify_content(char **file_content)
{
    char **content_fmt = str_to_word_array(file_content[0], ' ');
    int i = 0;
    while (content_fmt[i] != NULL) {
        if (i > 3) {
            free(content_fmt);
            return 0;
        }
        i++;
    }
    if (i < 3) {
        free(content_fmt);
        return 0;
    } else if (my_atoi(content_fmt[0]) == count_width(file_content) &&
        my_atoi(content_fmt[1]) == count_height(file_content) &&
        is_color(my_atoi(content_fmt[2])) == 1 &&
        is_a_tetriminos(file_content) != 1) {
        free(content_fmt);
        return 1;
    }
    free(content_fmt);
    return 0;
}

char *file_name(char *name)
{
    int check = 0;
    for (int i = 1; name[i] != '\0'; i++) {
        if (name[i] == '.' && name[i + 1] != '\0')
            check = 1;
    }
    if (check != 1)
        return NULL;
    char **file_format = str_to_word_array(name, '.');
    if (my_strcmp(file_format[1], "tetrimino") != 0)
        return NULL;
    return file_format[0];
}

int is_tetriminos(char *name)
{
    int fd = open(my_strcat("tetriminos/", name), O_RDONLY);
    if (fd == -1) {
        close(fd);
        return 0;
    }
    struct stat id;
    stat(my_strcat("tetriminos/", name), &id);
    char *buff = malloc(id.st_size);
    read(fd, buff, id.st_size);
    char **file_content = str_to_word_array(buff, '\n');
    if (verify_content(file_content) != 1) {
        free(file_content);
        close(fd);
        return 0;
    }
    free(file_content);
    close(fd);
    return 1;
}
