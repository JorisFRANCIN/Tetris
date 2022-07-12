/*
** EPITECH PROJECT, 2022
** main
** File description:
** init program
*/

#include "tetris.h"

void key_management(settings_t *settings, int opt)
{
    switch (opt) {
    case 'l':
        settings->mv_left = my_getnbr(optarg);
        break;
    case 'r':
        settings->mv_right = my_getnbr(optarg);
        break;
    case 't':
        settings->turn = my_getnbr(optarg);
        break;
    case 'd':
        settings->drop = my_getnbr(optarg);
        break;
    case 'q':
        settings->quit = my_getnbr(optarg);
        break;
    case 'p':
        settings->pause = my_getnbr(optarg);
        break;
    }
}

void settings_management(settings_t *settings, int opt)
{
    switch (opt) {
    case 'L':
        settings->lvl = my_getnbr(optarg);
        break;
    case 'w':
        settings->without_nxt = settings->without_nxt == 0 ? 1 : 0;
        break;
    case 'D':
        settings->debug = settings->debug == 0 ? 1 : 0;
        break;
    case 'm':
        char **opt_size = str_to_word_array(optarg, ',');
        settings->map_size = (dimension_t){my_getnbr(opt_size[0]),
            my_getnbr(opt_size[1])};
        break;
    case '?':
        exit(ERROR_ARG);
    }
}

settings_t *init_settings(void)
{
    settings_t *settings = malloc(sizeof(settings_t));
    settings->lvl = 1;
    settings->drop = KEY_DOWN;
    settings->map_size = (dimension_t){20, 10};
    settings->mv_left = KEY_LEFT;
    settings->mv_right = KEY_RIGHT;
    settings->pause = ' ';
    settings->quit = 'q';
    settings->turn = KEY_UP;
    settings->without_nxt = 0;
    settings->debug = 0;

    return settings;
}

static struct option *init_param(void)
{
    static struct option long_options[] = {{"help", 0, 0, 'h'},
        {"level", 1, 0, 'L'}, {"key-left", 1, 0, 'l'}, {"key-right", 1, 0, 'r'},
        {"key-turn", 1, 0, 't'}, {"key-drop", 1, 0, 'd'},
        {"key-quit", 1, 0, 'q'}, {"key-pause", 1, 0, 'p'},
        {"map-size", 1, 0, 'm'}, {"without-next", 0, 0, 'w'},
        {"debug", 0, 0, 'D'}, {0, 0, 0, 0}};

    return long_options;
}

int main(int argc, char **argv)
{
    struct option *long_options = init_param();
    settings_t *settings = init_settings();
    int opt;
    while ((opt = getopt_long(argc, argv, "L:l:r:t:d:q:p:wD", long_options,
        NULL)) != -1) {
        switch (opt) {
        case 'h':
            settings->help = settings->help == 0 && argc >= 2 ? 1 : 0;
            argc >= 2 ? 0 : exit(ERROR_ARG);
            break;
        }
        settings_management(settings, opt);
        key_management(settings, opt);
    }
    if (optind < argc)
        return ERROR_ARG;
    settings->help == 1 ? print_usage(settings, argv) : 0;
    settings->debug == 1 ? display_debug(settings) : 0;
    settings->help == 0 && settings->debug == 0 ? game(settings) : 0;
    return 0;
}
