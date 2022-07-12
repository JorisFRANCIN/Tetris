/*
** EPITECH PROJECT, 2021
** put_nbr_hex
** File description:
** Put number in Heximal base
*/

void my_putchar(char c);

int into_hex(unsigned int nb, char flag)
{
    int i = 0;

    if (flag == 'x') {
        for (i; i != nb % 10; i++) {
        }
        my_putchar(97 + i);
    }
    if (flag == 'X') {
        for (i; i != nb % 10; i++) {
        }
        my_putchar(65 + i);
    }
}

int my_put_nbr_hex(unsigned int nb, char flag)
{
    int nb1;
    int nb2;

    nb1 = nb % 16;
    nb2 = nb / 16;
    if (nb2 != 0) {
        my_put_nbr_hex(nb2, flag);
    }
    if (nb1 > 9) {
        into_hex(nb1, flag);
    } else {
        my_putchar(nb1 + '0');
    }
    return (0);
}
