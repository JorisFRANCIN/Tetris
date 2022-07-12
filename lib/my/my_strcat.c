/*
** EPITECH PROJECT, 2021
** my strcat
** File description:
** desc
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    int len = my_strlen(dest) + my_strlen(src);
    char *new_str = malloc(sizeof(char) * len + 1);

    while (i != len) {
        if (i < my_strlen(dest)) {
            new_str[i] = dest[i];
        } else {
            new_str[i] = src[j];
            j++;
        }
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}
