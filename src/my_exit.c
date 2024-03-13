/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-enzo.tiroumalle
** File description:
** my_exit
*/

#include "minishell.h"

void my_exit(shell_t *mshell)
{
    mshell->exit = 1;
    mshell->tty ? my_putstr("exit\n") : '0';
}
