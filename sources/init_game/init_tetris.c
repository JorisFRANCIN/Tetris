/*
** EPITECH PROJECT, 2022
** init_tetris
** File description:
** init the data of tetriminos in a struct
*/

#include "tetris.h"

char **mem_alloc_map(settings_t *settings)
{
    char **map = malloc(sizeof(char *) * settings->map_size.rows + 1);
    for (int i = 0; i != settings->map_size.rows; i++) {
        map[i] = malloc(sizeof(char) * settings->map_size.columns + 1);
        for (int j = 0; j != settings->map_size.columns; j++) {
            map[i][j] = ' ';
        }
        map[i][settings->map_size.columns] = '\0';
    }
    map[settings->map_size.rows] = NULL;
    return map;
}

char **mem_alloc_tetriminos(char **file_content, int square_size, int width,
    int height
)
{
    char **tetrimino = malloc(sizeof(char *) * square_size + 1);
    for (int i = 0; i != square_size; i++) {
        tetrimino[i] = malloc(sizeof(char) * square_size + 1);
        for (int j = 0; j != square_size; j++)
            tetrimino[i][j] = ' ';
        tetrimino[i][square_size] = '\0';
    }
    tetrimino[square_size] = NULL;
    for (int i = 0; i != height; i++) {
        for (int j = 0; j != width; j++)
            tetrimino[i][j] = file_content[i][j];
    }
    return tetrimino;
}

game_t *add_tetrimino(game_t *game_content, int nb, char *name)
{
    char *buff = open_tetriminos(name);
    char **file_content = str_to_word_array(buff, '\n');
    char **content_format = str_to_word_array(file_content[0], ' ');

    game_content->tetriminos[nb].width = my_atoi(content_format[0]);
    game_content->tetriminos[nb].height = my_atoi(content_format[1]);
    game_content->tetriminos[nb].color = my_atoi(content_format[2]);

    int square_size = my_atoi(content_format[0]) >= my_atoi(content_format[1]) ?
        my_atoi(content_format[0]) : my_atoi(content_format[1]);
    game_content->tetriminos[nb].size = square_size;
    game_content->tetriminos[nb].tetrimino = mem_alloc_tetriminos(
        &file_content[1], square_size, game_content->tetriminos[nb].width,
        game_content->tetriminos[nb].height);
    free(buff);
    free(file_content);
    free(content_format);
    return game_content;
}

game_t *insert_tetriminos(game_t *game_content, char *folderpath)
{
    DIR *file;
    struct dirent *content;
    int tetriminos = 0;
    file = opendir(folderpath);
    file == NULL ? exit(ERROR_FILE) : 0;
    while ((content = readdir(file)) != NULL) {
        struct stat id;
        char *name = content->d_name;
        stat(name, &id);
        if (name[0] != '.' && file_name(name) != NULL &&
            is_tetriminos(name) == 1) {
            tetriminos += 1;
            add_tetrimino(game_content, tetriminos - 1, name);
        }
    }
    tetriminos < 1 ? exit(84) : 0;
    game_content->nb_tetriminos = tetriminos;
    closedir(file);
    free(content);
    return game_content;
}

game_t *init_tetris(char *folderpath, settings_t *settings)
{
    initscr();
    nodelay(stdscr, TRUE);
    curs_set(0);
    start_color();
    keypad(stdscr, TRUE);
    noecho();
    game_t *game_content = malloc(sizeof(game_t));
    game_content->settings = settings;
    game_content->pause = 0;
    game_content->w = COLS;
    game_content->line = 0;
    game_content->high_score = 0;
    game_content->h = LINES;
    game_content->time.seconds = 0;
    game_content->time.minutes = 0;
    game_content->tetriminos = malloc(
        sizeof(tetriminos_t) * count_files(folderpath));
    insert_tetriminos(game_content, folderpath);
    game_content->score = 0;
    return game_content;
}
