/*
** EPITECH PROJECT, 2021
** my put nbr
** File description:
** description
*/

void my_putchar(char c);

int my_putstr(char const *str);

int my_put_nbr(int nb)
{
    int nb1 = 0;
    int nb2 = 0;

    if (nb < 0) {
        if (nb == -2147483648) {
            my_put_nbr(-nb + 1);
        } else {
            my_putchar('-');
            my_put_nbr(-nb);
        }
    } else {
        nb1 = nb % 10;
        nb2 = nb / 10;
        if (nb2 != 0) {
            my_put_nbr(nb2);
        }
        my_putchar(nb1 + '0');
    }
    return (0);
}
