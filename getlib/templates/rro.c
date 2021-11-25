/*
** EPITECH PROJECT, 2020
** bootstrap pushswap
** File description:
** rra_rrb
*/

#include <stdio.h>
#include "../include/lib.h"

void rro(t_list *list)
{
    t_element *temp = list->end->previous;

    list->end->previous = NULL;
    temp->next = NULL;
    list->end->next = list->begin;
    list->begin->previous = list->end;
    list->begin = list->end;
    list->end = temp;
}