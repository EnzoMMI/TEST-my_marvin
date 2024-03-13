/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-enzo.tiroumalle
** File description:
** tab_len
*/

#include "my.h"

int len_tab(char **tab)
{
    int len = 0;

    for (; tab[len] != NULL; ++len);
    return len;
}
