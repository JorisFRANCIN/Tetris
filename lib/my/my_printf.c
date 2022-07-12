/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** Replica of the my_printf function
*/

#include <stdarg.h>
#include <stdio.h>

void my_putchar(char c);

int my_putstr(char const *str);

int my_putstr2(char const *str, int flag2);

int my_put_nbr(int nb);

int my_put_nbr2(unsigned int nb);

int my_put_nbr_base(unsigned int nb, int flag2);

int my_put_nbr_hex(unsigned int nb, char flag);

int my_put_nbr_binary(unsigned int nb);

void flag_access_default(char flag, va_list arg, int flag2)
{
    if (flag == 'c') {
        my_putchar(va_arg(arg, int));
    }
    if (flag == 's') {
        my_putstr(va_arg(arg, char *));
    }
    if (flag == 'd' || flag == 'i') {
        my_put_nbr(va_arg(arg, int));
    }
    if (flag == 'S') {
        my_putstr2(va_arg(arg, char *), flag2);
    }
    if (flag == 'u') {
        my_put_nbr2(va_arg(arg, int));
    }
}

void flag_access_base(char flag, va_list arg, int flag2)
{
    if (flag == 'x' || flag == 'X') {
        my_put_nbr_hex(va_arg(arg, int), flag);
    }
    if (flag == 'b') {
        my_put_nbr_binary(va_arg(arg, int));
    }
    if (flag == 'o') {
        my_put_nbr_base(va_arg(arg, int), flag2);
    }
}

void flag_access(char flag, va_list arg)
{
    int flag2 = 1;

    if (flag == 'c' || flag == 's' || flag == 'u' || flag == 'd' ||
        flag == 'i' || flag == 'S') {
        flag_access_default(flag, arg, flag2);
    }
    if (flag == 'x' || flag == 'X' || flag == 'b' || flag == 'o') {
        flag_access_base(flag, arg, flag2);
    }
    if (flag == '%') {
        my_putchar('%');
    }
    if (flag == 'p') {
        my_putstr("0x");
        my_put_nbr_hex(va_arg(arg, int), 'x');
    }
}

void *my_printf(char const *format, ...)
{
    va_list(arg);

    va_start(arg, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            flag_access(format[i + 1], arg);
            i++;
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(arg);
    return 0;
}
