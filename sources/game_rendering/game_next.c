/*
** EPITECH PROJECT, 2022
** game_next
** File description:
** Display the box that contains the tetriminos that comes
*/

#include "tetris.h"

void game_next(settings_t *settings, game_t *game_content)
{
    int index = game_content->next_tetrimino;
    WINDOW *nxt = newwin(LINES / 3, 25, 8, (COLS - 10) - (LINES / 3));
    if (settings->without_nxt == 0) {
        refresh();
        wborder(nxt, '"', '"', '=', '=', '<', '>', '<', '>');
        mvwprintw(nxt, 1, ((LINES / 3) / 2) + (5 / 2), "NEXT:");
        for (int i = 0; i != game_content->tetriminos[index].size; i++) {
            mvwprintw(nxt, ((LINES / 3) / 2) + i -
                    (game_content->tetriminos[index].size / 2),
                (25 / 2) - (game_content->tetriminos[index].size / 2),
                game_content->tetriminos[index].tetrimino[i]);
        }
        wrefresh(nxt);
    }
}
