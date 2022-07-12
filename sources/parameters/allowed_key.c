/*
** EPITECH PROJECT, 2022
** allowed_key.c
** File description:
** Verify if the selected new key is available as a new ctrl
*/

#include "tetris.h"

int allowed_key(settings_t *settings, int key)
{
    if (key == settings->mv_left || key == settings->quit ||
        key == settings->mv_right || key == settings->pause ||
        key == settings->turn) {
        exit(UNCORRECT_KEY);
    }
    return key;
}
