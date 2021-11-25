/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** my_putnbr
*/

#include <stdio.h>

void my_putnbr(int nb)
{
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + '0');
    }
    else {
        my_putnbr(nb/10);
        my_putchar(nb%10 + 48);
    }
}
