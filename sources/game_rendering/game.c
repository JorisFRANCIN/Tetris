/*
** EPITECH PROJECT, 2022
** game
** File description:
** launch game
*/

#include "tetris.h"

void game_box(game_t *game_content, settings_t *settings)
{
    refresh();
    game_content->render_window = newwin(settings->map_size.rows + 2,
        settings->map_size.columns + 2,
        game_content->h / 2 - (settings->map_size.rows / 2) - 1,
        game_content->w / 2 - (settings->map_size.columns / 2) - 1);
    wborder(game_content->render_window, '|', '|', '-', '-', '+', '+', '+',
        '+');
    for (int i = 0; game_content->map[i] != NULL; i++) {
        mvwprintw(game_content->render_window, i + 1, 1, game_content->map[i]);
    }
    wrefresh(game_content->render_window);
}

void game_stat(settings_t *settings, int time, int time2, game_t *content)
{
    WINDOW *stat = newwin(content->h / 3, 25, 8, 2);
    retrieve_data(content);
    refresh();
    box(stat, '|', '-');
    mvwprintw(stat, 1, 1, "High Score: %d",
        content->high_score = keep_data(content));
    mvwprintw(stat, 2, 1, "Score: %d", content->score);
    mvwprintw(stat, 8 - 1, 1, "Lines: %d", content->line);
    mvwprintw(stat, 8, 1, "Level: %d", settings->lvl);
    mvwprintw(stat, 8 * 2 - 1, 1, "Timer: %d:%d", time2 / 2, time / 2);
    wrefresh(stat);
    game_box(content, settings);
    game_next(settings, content);
}

void game_border(int time)
{
    wborder(stdscr, '|', '|', '=', '=', '/', '\\', '\\', '/');
    char **logo = str_to_word_array(
        "  _______ ______ _______ _____  _____  _____ \n"
        " |__   __|  ____|__   __|  __ \\|_   _|/ ____|\n"
        "    | |  | |__     | |  | |__) | | | | (___  \n"
        "    | |  |  __|    | |  |  _  /  | |  \\___ \\ \n"
        "    | |  | |____   | |  | | \\ \\ _| |_ ____) |\n"
        "    |_|  |______|  |_|  |_|  \\_\\_____|_____/ \n", '\n');
    for (int i = 0; logo[i] != NULL; i++) {
        init_pair(2, time % 7 + 1, COLOR_BLACK);
        attron(COLOR_PAIR(2));
        mvprintw(1 + i, 1, logo[i]);
        attroff(COLOR_PAIR(2));
    }
}

void game_display(settings_t *settings, int s, int m, game_t *game_content)
{
    if (game_content->h == 52 && game_content->w == 190) {
        game_border(s);
        game_stat(settings, s, m, game_content);
        if (game_content->current_tetrimino[0][0].y +
            game_content->tetriminos[game_content->index_tetrimino].height <
            game_content->settings->map_size.rows &&
            is_blocked(game_content) < 1)
            falling_rules(game_content);
        else if (win_line(game_content) == 0) {
            game_content->index_tetrimino = rendering_tetriminos(game_content,
                game_content->next_tetrimino);
            game_content->next_tetrimino = rand() % game_content->nb_tetriminos;
        }
    } else
        mvprintw(game_content->h / 2,
        game_content->w / 2 - my_strlen(RESIZE_MESSAGE), "%s",
        RESIZE_MESSAGE);
    win_line(game_content);
}

int game(settings_t *settings)
{
    srand(time(NULL));
    game_t *game_content = init_tetris("tetriminos", settings);
    assume_default_colors(COLOR_CYAN, COLOR_BLACK);
    game_content->map = mem_alloc_map(settings);
    int r = rand() % game_content->nb_tetriminos;
    game_content->index_tetrimino = rendering_tetriminos(game_content, r);
    game_content->next_tetrimino = rand() % game_content->nb_tetriminos;
    for (int key, s = game_content->time.seconds, m = game_content->
        time.minutes; key != settings->quit;
        napms(500 / settings->lvl), settings->lvl +=
        s == 59 ? 1 : 0, m += s == 59 ? 1 : 0, s +=
        s < 59 ? 1 : -59, key = getch()) {
        game_content->w = COLS;
        game_content->h = LINES;
        game_move_tetriminos(game_content, settings, key);
        game_display(settings, s, m, game_content);
    }
    endwin();
    free_all(settings, game_content);
    return 0;
}
