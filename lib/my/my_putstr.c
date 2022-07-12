/*
** EPITECH PROJECT, 2021
** my putstr
** File description:
** Description
*/

void my_putchar(char d);

int my_putstr(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return (0);
}
