/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-enzo.tiroumalle
** File description:
** free_list
*/

#include "../my.h"

void free_list(list_t *head)
{
    list_t *cur = head;
    list_t *tmp;

    if (head == NULL)
        return;
    for (; cur != NULL; ) {
        tmp = cur->next;
        if (cur && cur->name)
            free(cur->name);
        if (cur && cur->value)
            free(cur->value);
        free(cur);
        cur = tmp;
    }
}
