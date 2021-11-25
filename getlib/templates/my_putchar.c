/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** my_putchar
*/

#include <unistd.h>
#include <stdio.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
