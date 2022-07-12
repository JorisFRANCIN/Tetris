/*
** EPITECH PROJECT, 2021
** atoi
** File description:
** Replica of atoi
*/

int my_atoi(char const *str)
{
    int flag = 1;
    int i = 0;
    int result = 0;

    while (str[i] != '\0' && flag == 1) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        } else {
            flag = 2;
            return result = -1;
        }
        i++;
    }
    return result;
}
