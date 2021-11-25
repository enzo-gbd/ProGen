/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-minishell1-enzo.gouband
** File description:
** str_to_word_array
*/

#include <stdio.h>

int str_size(char *str)
{
    int count = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i + 1] != ' ')
            count += 1;
    }
    return (count);
}

char **my_malloc(char **array, int size)
{
    array = malloc(size * sizeof(char *));

    for (int i = 0; i < size; i++)
        array[i] = malloc(20 * sizeof(char));
    return (array);
}

char **str_to_word_array(char *str)
{
    char **array = my_malloc(array, str_size(str));
    int n = 0;
    int x = 0;
    int y = 0;

    while (str[n] != '\0') {
        if (str[n] == '\\' && (str[n + 1] < 123 && str[n + 1] > 96))
            n += 2;
        if (str[n] != ' ')
            array[y][x] = str[n];
        n += 1;
        x += 1;
        if (str[n] == ' ' && str[n + 1] != ' ') {
            n += 1;
            y += 1;
            x = 0;
        }
    }
    array[y][x] = '\0';
    return (array);
}