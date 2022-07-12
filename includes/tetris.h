/*
** EPITECH PROJECT, 2022
** tetris.h
** File description:
** .h file
*/

#ifndef TETRIS_H_
    #define TETRIS_H_

    #include "curses.h"
    #include "my.h"
    #include "my_struct.h"
    #include "macro.h"

int print_usage(settings_t *settings, char **argv);
char **delete_space_tetris(char **file_content);
void display_debug(settings_t *settings);
int count_files(char const *folderpath);
int game(settings_t *settings);
int is_tetriminos(char *name);
char *file_name(char *name);
int count_width(char **file_content);
int count_height(char **file_content);
int is_color(int color);
char *open_tetriminos(char *name);
int is_a_tetriminos(char **file_content);
int allowed_key(settings_t *settings, int key);
int content_message(char *name, int flag);
game_t *init_tetris(char *folderpath, settings_t *settings);
char **rotate_left(char **matrix, int size);
char **mem_alloc_map(settings_t *settings);
int rendering_tetriminos(game_t *game_content, int r);
void free_all(settings_t *settings, game_t *game_content);
int falling_rules(game_t *game_content);
void game_next(settings_t *settings, game_t *game_content);
void game_move_tret(game_t *content, settings_t *settings, int key);
game_t *swap_array_element(game_t *game_content, position_t pos1,
position_t pos2);
int is_blocked(game_t *game_content);
int can_go_left(game_t *content);
int can_go_right(game_t *content);
void game_move_tetriminos(game_t *content, settings_t *settings, int key);
void game_drop_tetrimino(game_t *content, settings_t *settings, int key);
void game_turn_tetriminos(game_t *content, settings_t *settings, int key);
int win_line(game_t *content);
int keep_data(game_t *content);
int new_high_score(game_t *content);
int retrieve_data(game_t *content);
game_t *turn_matrix(game_t *content);
char **cp_tetris(game_t *content, int size);
game_t *change_pos(game_t *content, int x);

#endif
