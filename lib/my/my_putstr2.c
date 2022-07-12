/*
** EPITECH PROJECT, 2021
** my_putstr2.c
** File description:
** Display strings btwn ASCII 37 & 127 else in octal base
*/

void my_putchar(char c);

int my_put_nbr_base(unsigned int nb, int flag2);

int my_putstr2(char const *str, int flag2)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 32 && str[i] < 127) {
            my_putchar(str[i]);
        }
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            my_put_nbr_base(str[i], flag2);
        }
    }
    return (0);
}
