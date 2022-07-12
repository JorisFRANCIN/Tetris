/*
** EPITECH PROJECT, 2022
** print_help
** File description:
** print the usage of tetris
*/

#include "tetris.h"

int print_usage(settings_t *settings, char **argv)
{
    my_printf("Usage: %s [options]\nOptions:\n   --help  Display this help\n"
    "   -L --level=%d    Start Tetris at level num (def: 1)\n   -l --key-left="
    "%d   Move the tetrimino LEFT using the K key (def: left arrow)\n"
    "   -r --key-right=%d  Move the tetrimino RIGHT using the K key"
    " (def: right arrow)\n"
    "   -t --key-turn=%d   TURN the tetrimino clockwise 90d using the K key"
    " (def: top arrow)\n"
    "   -d --key-drop=%d   DROP the tetrimino using the K key"
    " (def: down arrow)\n"
    "   -q --key-quit=%d   QUIT the game using the K key (def: 'q' key)\n"
    "   -p --key-pause=%d  PAUSE/RESTART the game using the K key"
    " (def: space bar)\n"
    "   --map-size=%d,%d    Set the numbers of rows and columns of the map"
    " (def: 20,10)\n"
    "   -w --without-next   Hide next tetrimino (def: false)\n"
    "   -D --debug  Debug mode (def: false)\n", argv[0], settings->lvl,
    settings->mv_left, settings->mv_right, settings->turn, settings->drop,
    settings->quit, settings->pause, settings->map_size.rows,
    settings->map_size.columns);
    return 0;
}
