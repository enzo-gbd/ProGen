/*
** EPITECH PROJECT, 2020
** bootstrap pushswap
** File description:
** pa_pb
*/

#include <stdio.h>
#include "../include/list.h"

element_t *malloc_temp(element_t *temp)
{
    temp->next = malloc(sizeof(element_t));
    return (temp);
}

list_t *create_list(int size)
{
    list_t *list = malloc(sizeof(list_t));
    list->begin = malloc(sizeof(element_t));
    element_t *temp = list->begin;
    int count_tower = 1;

    list->begin->previous = NULL;
    while (count_tower <= size) {
        if (count_tower < size) {
            temp = malloc_temp(temp);
            temp->next->previous = temp;
            temp = temp->next;
        }
        else if (count_tower == size) {
            temp->next = NULL;
            list->end = temp;
        }
        count_tower += 1;
    }
    return (list);
}