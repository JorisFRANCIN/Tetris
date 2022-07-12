/*
** EPITECH PROJECT, 2021
** my put nbr
** File description:
** description
*/

void my_putchar(char c);

int my_put_nbr2(unsigned int nb)
{
    int nb1;
    int nb2;

    nb1 = nb % 10;
    nb2 = nb / 10;
    if (nb2 != 0) {
        my_put_nbr2(nb2);
    }
    my_putchar(nb1 + '0');
    return (0);
}
