/*
** EPITECH PROJECT, 2021
** put_nbr_base
** File description:
** Put number in it octal base
*/

void my_putchar(char c);

int my_putstr(char const *str);

int add_zero(int nb)
{
    if (nb <= 7) {
        my_putstr("00");
    } else if (nb > 7 && nb <= 77) {
        my_putchar('0');
    } else {
        return 0;
    }
}

int my_put_nbr_base(unsigned int nb, int flag2)
{
    int nb1;
    int nb2;
    int nb3 = 0;

    nb1 = nb % 8;
    nb2 = nb / 8;
    if (nb3 == 0 && flag2 == 1) {
        flag2 = 2;
        nb3 = nb2 * 10 + nb1;
        add_zero(nb3);
    }
    if (nb2 != 0) {
        my_put_nbr_base(nb2, flag2);
    }
    my_putchar(nb1 + '0');
    return (0);
}
