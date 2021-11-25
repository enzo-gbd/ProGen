/*
** EPITECH PROJECT, 2021
** B-PSU-200-BDX-2-1-mysokoban-enzo.gouband
** File description:
** file_to_map
*/

#include <stdio.h>

char **malloc_array(int nb_rows, int nb_colums)
{
    char **array = malloc(sizeof(char *) * nb_rows + 1);

    for (int i = 0; i < nb_rows; i += 1)
        array[i] = malloc(nb_colums * sizeof(char) + 1);
    return (array);
}