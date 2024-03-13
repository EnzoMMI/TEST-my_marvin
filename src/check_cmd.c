/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** check_cmd
*/

#include "minishell.h"

int check_my_command(shell_t *mshell)
{
    char *flags[] = {"cd", "setenv", "unsetenv", "env", "exit"};
    void (*tabp[])(shell_t *mshell) = {
        my_cd, my_setenv, my_unsetenv, my_env, my_exit
    };

    for (int i = 0; i != 5; ++i) {
        if (my_strcmp(mshell->tab[0], flags[i]) == 0) {
            tabp[i](mshell);
            return 0;
        }
    }
    return 1;
}

int check_command(shell_t *mshell)
{
    exe_cmd(mshell);
    free(mshell->cmd);
    exit(mshell->error);
}
