/*
** EPITECH PROJECT, 2020
** B-PSU-101-BDX-1-1-navy-enzo.gouband
** File description:
** my_bin_to_dec
*/

#include <stdio.h>

int my_bin_to_dec(char *bin)
{
    int dec = 0;
    if (bin[0] == '1')
        dec += 1;
    if (bin[1] == '1')
        dec += 2;
    if (bin[2] == '1')
        dec += 4;
    return (dec);
}