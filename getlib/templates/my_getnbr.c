/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** day10
*/

#include <stdio.h>

int my_neg(char c)
{
    int p = 1;

    if (c == '-') {
        p = p * (-1);
    }
    return (p);
}

int my_put_int(int i, char *str)
{
    int nb = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
            i = i + 1;
        } else {
            return (nb);
        }
    }
    return (nb);
}

int my_getnbr(char *str)
{
    int n = 0;
    int pos = 1;
    int nb;

    while (str[n] == '+' || str[n] == '-') {
        pos = my_neg(str[n]);
        n = n + 1;
    }
    nb = my_put_int(n, str) * pos;
    return (nb);
}
