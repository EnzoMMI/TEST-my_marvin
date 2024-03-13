/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-enzo.tiroumalle
** File description:
** free_node
*/

#include "../my.h"

void free_node(list_t **head, char *name)
{
    cell_t *cur = *head;
    cell_t *prev = NULL;

    for (; cur != NULL && my_strcmp(cur->name, name) != 0; cur = cur->next)
        prev = cur;
    if (cur == NULL)
        return;
    if (prev == NULL)
        *head = cur->next;
    else
        prev->next = cur->next;
    free(cur->name);
    free(cur->value);
    free(cur);
}
