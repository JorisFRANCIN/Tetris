/*
** EPITECH PROJECT, 2022
** nbr_to_str
** File description:
** Integer into a string
*/

#include "my.h"

int my_nbrlen(int nb)
{
    int i = 0;

    while (nb / 10 != 0) {
        nb = nb / 10;
        i++;
    }
    return i;
}

char *nbr_to_str(int nb)
{
    int len = my_nbrlen(nb);
    int divide = 0;
    int real_length = len;
    char *str = malloc(sizeof(char) * len + 1);
    int i = 0;

    for (i = 0; i != real_length + 1; i++, len--) {
        divide = my_compute_power_rec(10, len);
        str[i] = nb / divide + '0';
        nb = nb % divide;
    }
    str[i] = '\0';
    return str;
}
