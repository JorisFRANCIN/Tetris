/*
** EPITECH PROJECT, 2022
** display_debug
** File description:
** display the debug option
*/

#include "tetris.h"

void tetriminos_file(char const *folderpath)
{
    DIR *file;
    struct dirent *content;
    int tetriminos = 0;

    file = opendir(folderpath);
    file == NULL ? exit(ERROR_FILE) : 0;
    int count = count_files(folderpath);
    my_printf("Number of tetriminos: %d\n", count);
    while ((content = readdir(file)) != NULL) {
        struct stat id;
        char *name = content->d_name;
        stat(name, &id);
        if (name[0] != '.' && file_name(name) != NULL) {
            tetriminos += content_message(name, is_tetriminos(name));
        }
    }
    tetriminos < 1 ? exit(84) : 0;
    closedir(file);
}

void game_mode(settings_t *settings)
{
    my_printf("Next: %s\n", settings->without_nxt == 0 ? "Yes" : "No");
    my_printf("Level: %d\n", settings->lvl);
    my_printf("Size: %d*%d\n", settings->map_size.rows,
    settings->map_size.columns);
}

void keys_ctrl(settings_t *settings)
{
    my_printf("Key left: %s (%d)\n", keyname(settings->mv_left),
        settings->mv_left);
    my_printf("Key right: %s (%d)\n", keyname(settings->mv_right),
        settings->mv_right);
    my_printf("Key turn: %s (%d)\n", keyname(settings->turn), settings->turn);
    my_printf("Key drop: %s (%d)\n", keyname(settings->drop), settings->drop);
    my_printf("Key quit: %s (%d)\n", keyname(settings->quit), settings->quit);
    my_printf("Key pause: %s (%d)\n", keyname(settings->pause),
    settings->pause);
}

void display_debug(settings_t *settings)
{
    keys_ctrl(settings);
    game_mode(settings);
    my_printf("\n");
    tetriminos_file("tetriminos");
}
