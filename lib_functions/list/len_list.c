/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-enzo.tiroumalle
** File description:
** len_list
*/

#include "../my.h"

int list_len(list_t *head)
{
    list_t *tmp = head;
    int len = 0;

    for (; tmp; tmp = tmp->next)
        ++len;
    return len;
}
