/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-enzo.tiroumalle
** File description:
** check_tab
*/

#include "my.h"

void check_tab(char **tab)
{
    if (tab != NULL) {
        free_tab(tab);
        free(tab);
    }
}
