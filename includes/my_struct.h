/*
** EPITECH PROJECT, 2022
** my_struct.h
** File description:
** .h file
*/

#ifndef MY_STRUCT_H_
    #define MY_STRUCT_H_

typedef struct dimension_s {
    int rows;
    int columns;
} dimension_t;

typedef struct position_s {
    int y;
    int x;
} position_t;

typedef struct tetriminos_s {
    int width;
    int height;
    int color;
    int size;
    char **tetrimino;
} tetriminos_t;

typedef struct settings_s {
    int lvl;
    int mv_left;
    int mv_right;
    int turn;
    int drop;
    int quit;
    int pause;
    int without_nxt;
    int debug;
    int help;
    dimension_t map_size;
} settings_t;

typedef struct game_time_s {
    int seconds;
    int minutes;
} game_time_t;

typedef struct game_s {
    char **map;
    WINDOW *render_window;
    game_time_t time;
    tetriminos_t *tetriminos;
    settings_t *settings;
    position_t **current_tetrimino;
    int pause;
    int line;
    int w;
    int h;
    int index_tetrimino;
    int next_tetrimino;
    int nb_tetriminos;
    int high_score;
    int score;
} game_t;

#endif /* !MY_STRUCT_H_ */
