/*
** EPITECH PROJECT, 2019
** new
** File description:
** lol
*/

int pre_loop(char const *str, int i)
{
    while (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
        i++;
    return (i);
}

int my_getnbr(char const *str)
{
    long nb = 0;
    int i = 0;
    int counter = 2;

    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9')) {
        nb = nb * 10;
        nb = nb + str[i] - 48;
        if (nb > 2147483647 || nb < -2147483647)
            return (0);
        i++;
    }
    if (counter % 2 == 1)
        nb = nb * -1;
    return (nb);
}