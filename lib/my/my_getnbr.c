/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** decription
*/

#include "my.h"

int seek_sign(char const *str)
{
    int i;
    int sign = 1;

    for (i = 0; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '+') {
            sign *= 1;
        } else if (str[i] == '-') {
            sign *= -1;
        }
    }
    return (sign);
}

int start_line(char const *str)
{
    int flag = 1;
    int i = 0;

    while (str[i] != '\0' && flag == 1) {
        if (str[i] >= '0' && str[i] <= '9') {
            return i;
            flag = 2;
        }
        i++;
    }
    exit(84);
    return -1;
}

int my_getnbr(char const *str)
{
    int i = start_line(str);
    int result = 0;

    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result *= seek_sign(str);
}
