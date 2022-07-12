/*
** EPITECH PROJECT, 2022
** count_files
** File description:
** count files in a dir
*/

#include "tetris.h"

int is_a_tetriminos(char **file_content)
{
    int count = 0;
    for (int i = 1; file_content[i] != NULL; i++) {
        for (int j = 0; file_content[i][j] != '\0'; j++) {
            count += file_content[i][j] != '*' && file_content[i][j] != ' ' ?
            1 : 0;
        }
    }
    return count;
}

int count_files(char const *folderpath)
{
    int count = 0;
    DIR *file;
    struct dirent *content;
    file = opendir(folderpath);

    while ((content = readdir(file)) != NULL) {
        struct stat id;
        char *name = content->d_name;
        stat(name, &id);
        name[0] != '.' && file_name(name) != NULL ? count++ : 0;
    }
    return count;
    closedir(file);
}

int count_width(char **file_content)
{
    int count = 0;
    int tmp = 0;
    delete_space_tetris(file_content);
    for (int i = 1; file_content[i] != NULL; i++, tmp = 0) {
        for (int j = 0; file_content[i][j] != '\0'; j++)
            tmp++;
        if (tmp > count)
            count = tmp;
    }
    return count;
}

int count_height(char **file_content)
{
    int count = 0;
    for (int i = 1; file_content[i] != NULL; i++) {
        count++;
    }
    return count;
}

int is_color(int color)
{
    if (color < 0 && color > 7)
        return 0;
    return 1;
}
