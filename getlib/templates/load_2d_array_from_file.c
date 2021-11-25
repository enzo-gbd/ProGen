/*
** EPITECH PROJECT, 2021
** load_2d_array_from_file
** File description:
** load_2d_array_from_file
*/

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *load_file(char *filepath)
{
    int size;
    char *buff = NULL;
    FILE *file = fopen(filepath, "r");
    struct stat *st = malloc(sizeof(struct stat));

    if (file == NULL)
        return (NULL);
    stat(filepath, st);
    size = st->st_size;
    buff = malloc(size + 1);
    fread(buff, 1, size, file);
    buff[size] = '\0';
    fclose(file);
    free(st);
    return (buff);
}

int count_rows(char *buff)
{
    int rows = 1;

    for (int i = 0; buff[i] != '\0'; i += 1) {
        if (buff[i] == '\n')
            rows += 1;
    }
    return (rows);
}

char **mem_alloc_array(char *buff)
{
    char **array = malloc(sizeof(char *) * (count_rows(buff) + 1));
    int count = 1;
    int curr_row = 0;

    for (int i = 0; buff[i] != '\0'; i += 1) {
        if (buff[i] == '\n') {
            array[curr_row] = malloc(count + 1);
            curr_row += 1;
            count = 1;
        } else
            count += 1;
    }
    array[curr_row] = malloc(count + 1);
    array[curr_row + 1] = NULL;
    return (array);
}

char **fill_map(char **array, char *buff)
{
    int count = 0;
    int curr_row = 0;

    for (int i = 0; buff[i] != '\0'; i += 1) {
        if (buff[i] == '\n') {
            array[curr_row][count] = '\0';
            curr_row += 1;
            count = 0;
        } else {
            array[curr_row][count] = buff[i];
            count += 1;
        }
    }
    array[curr_row][count] = '\0';
    free(buff);
    return (array);
}

char **load_2d_array_from_file(char *filepath)
{
    char *file = load_file(filepath);
    if (file == NULL)
        return (NULL);
    char **array = mem_alloc_array(file);

    array = fill_map(array, file);
    return (array);
}
