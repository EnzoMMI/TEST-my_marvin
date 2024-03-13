/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** free_tab
*/

#include "my.h"

void free_tab(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; ++i)
        free(tab[i]);
    free(tab[i]);
}
