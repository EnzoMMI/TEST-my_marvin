/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-enzo.tiroumalle
** File description:
** add_to_list
*/

#include "../my.h"

void add_node(list_t **head, char *name, char *value)
{
    list_t *new_cell = create_node(name, value);
    list_t *tmp = *head;

    if (*head == NULL) {
        *head = new_cell;
        return;
    }
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = new_cell;
}
