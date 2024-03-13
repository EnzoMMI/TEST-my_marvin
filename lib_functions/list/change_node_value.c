/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-enzo.tiroumalle
** File description:
** change_node_value
*/

#include "../my.h"

void change_node_value(list_t **head, char *name, char *value)
{
    cell_t *cur = *head;

    for (; cur != NULL; cur = cur->next) {
        if (my_strcmp(cur->name, name) == 0) {
            free(cur->value);
            cur->value = value;
            return;
        }
    }
}
