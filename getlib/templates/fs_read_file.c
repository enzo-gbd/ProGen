/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-pierre.woelffel
** File description:
** fs_read_file
*/

#include <unistd.h>

int fs_read_file(int fd, char *buffer, int size)
{
    int out = read(fd, buffer, size);

    if (out != size)
        return (84);
    buffer[size] = '\0';
    close(fd);
    return (0);
}