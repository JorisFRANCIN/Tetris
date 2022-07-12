/*
** EPITECH PROJECT, 2022
** str_to_word_array
** File description:
** Transform a string into an array
*/

#include "my.h"

int word_length(char const *str, int j, char c)
{
    int length = 0;

    while (str[j] != c && str[j] != '\0') {
        if (str[j] >= 32 && str[j] < 127)
            length++;
        j++;
    }
    return length;
}

int count_word(char const *str, char c)
{
    int words = 0;

    for (int i = 0; i != my_strlen(str); i++) {
        if (str[i] == c && str[i + 1] >= 32 && str[i + 1] < 127)
            words++;
    }
    return words;
}

char **str_to_word_array(char const *str, char c)
{
    int i = 0;
    int j = 0;
    int tmp = 0;
    int word_len = word_length(str, j, c);
    char **new_argv = malloc(sizeof(char *) * count_word(str, c) + 1);

    for (i = 0; i != count_word(str, c) + 1; i++, j++, tmp = 0) {
        word_len = word_length(str, j, c);
        new_argv[i] = malloc(sizeof(char) * word_length(str, j, c) + 1);
        while (tmp != word_len) {
            new_argv[i][tmp] = str[j];
            tmp++;
            j++;
        }
        new_argv[i][tmp] = '\0';
    }
    new_argv[i] = NULL;
    return new_argv;
}
