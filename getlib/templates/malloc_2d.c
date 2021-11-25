/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-enzo.gouband
** File description:
** malloc_2d
*/

#include <stdio.h>

char **malloc_2d(int x, int y)
{
    char **array = malloc(sizeof(char *) * (y + 1));
    if (array == NULL)
        return (NULL);

    for (int i = 0; i < y; i++) {
        array[i] = malloc(x + 1);
        if (array[i] == NULL)
            return (NULL);
    }
    return (array);
}