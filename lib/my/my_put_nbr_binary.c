/*
** EPITECH PROJECT, 2021
** put_nbr_binary
** File description:
** Put number in binary base
*/

void my_putchar(char c);

int my_put_nbr_binary(unsigned int nb)
{
    int nb1;
    int nb2;

    nb1 = nb % 2;
    nb2 = nb / 2;
    if (nb2 != 0) {
        my_put_nbr_binary(nb2);
    }
    my_putchar(nb1 + '0');
    return (0);
}
