/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-enzo.tiroumalle
** File description:
** error
*/

#include "minishell.h"

int key_error(shell_t *mshell)
{
    if (mshell->line[0] == '\n')
        return 0;
}
