/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** Initiation of the program
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int count = 0;
    int i = 0;

    if (my_strlen(s1) - my_strlen(s2) == 0) {
        while (i != my_strlen(s1)) {
            count += s1[i] - s2[i];
            i++;
        }
        return count;
    }
    return 1;
}
