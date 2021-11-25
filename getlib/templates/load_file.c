/*
** EPITECH PROJECT, 2020
** duo_stumper
** File description:
** load_file.c
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int fs_open_file2(char *filepath)
{
    int fd = open(filepath, O_RDONLY);

    return (fd);
}

char *load_file(char *path)
{
    int fd = fs_open_file2(path);
    if (fd == -1)
        return (NULL);
    struct stat buf;
    stat(path, &buf);
    char *str = malloc(sizeof(char) * (buf.st_size + 1));
    if (str == NULL)
        return (NULL);
    size_t buf_s = buf.st_size;
    int a = read(fd, str, buf_s);

    if (buf.st_size == 0)
        return (NULL);
    str[a] = '\0';
    return (str);
}