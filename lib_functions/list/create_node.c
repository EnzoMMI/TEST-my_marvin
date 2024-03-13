/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-enzo.tiroumalle
** File description:
** create_node
*/

#include "../my.h"

list_t *create_node(char *name, char *value)
{
    list_t *new_cell = malloc(sizeof(list_t));

    new_cell->name = name;
    new_cell->value = value;
    new_cell->next = NULL;
    return new_cell;
}
