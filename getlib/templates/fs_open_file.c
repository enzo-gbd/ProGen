/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-pierre.woelffel
** File description:
** fs_open_file
*/

#include <stdlib.h>
#include <fcntl.h>

int fs_open_file(char const *filepath)
{
    int fd;

    fd = open(filepath, O_RDONLY);
    if (fd != -1) {
        return (fd);
    } else {
        return (84);
    }
}