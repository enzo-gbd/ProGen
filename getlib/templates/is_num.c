/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-enzo.gouband
** File description:
** is_num
*/

#include <stdio.h>

int is_num(char *str)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != '\n') {
        if ((str[i] < 48 || str[i] > 57) && str[i] != 45)
            return (0);
        i += 1;
    }
    return (1);
}