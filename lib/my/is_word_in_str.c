/*
** EPITECH PROJECT, 2022
** is_word_in_str
** File description:
** Find if a word is in a string
*/

#include "my.h"

int is_word_in_str(char *word, char *str)
{
    int tmp = 0;
    for (int i = 0; i != my_strlen(str) - my_strlen(word); i++) {
        tmp = 0;
        for (int j = i; j != my_strlen(word); j++) {
            tmp = str[j] - word[j];
        }
        if (tmp == 0)
            return 1;
    }
    return 0;
}
