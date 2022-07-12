/*
** EPITECH PROJECT, 2021
** my compute power rec
** File description:
** Description
*/

int my_compute_power_rec(int nb, int p)
{
    int result;

    result = nb;
    if (p == 0) {
        result = 1;
    }
    if (nb == 0 || p < 0) {
        result = 0;
    }
    if (nb == 0 && p == 0) {
        result = 1;
    }
    if (p == 1 && nb > 0) {
        result = nb;
    }
    if (p > 1) {
        p--;
        result = result * my_compute_power_rec(nb, p);
    }
    return (result);
}
