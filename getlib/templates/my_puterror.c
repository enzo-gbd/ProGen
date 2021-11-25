/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** my_putstr
*/

#include <stdio.h>

void my_puterror(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i += 1;
    }
}