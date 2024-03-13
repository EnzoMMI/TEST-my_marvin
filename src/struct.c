/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-enzo.tiroumalle
** File description:
** struct
*/

#include "minishell.h"

void init_struct2(shell_t *mshell, char **argv, char **env)
{
    mshell->all_cmd = NULL;
}

void init_strcut(shell_t *mshell, char **argv, char **env)
{
    mshell->error = 0;
    mshell->exit = 0;
    mshell->line = NULL;
    mshell->size_env = 0;
    mshell->env = NULL;
    mshell->tab = NULL;
    mshell->curr_path = NULL;
    my_getenv(mshell, env);
    if (isatty(STDIN_FILENO))
        mshell->tty = 1;
    else
        mshell->tty = 0;
}

void free_struct(shell_t *mshell)
{
    free(mshell->curr_path);
    free_list(mshell->env);
    free_tab(mshell->my_env);
    free(mshell->my_env);
    if (mshell->tab != NULL) {
        free_tab(mshell->tab);
        free(mshell->tab);
    }
    if (mshell->all_cmd != NULL) {
        free_tab(mshell->all_cmd);
        free(mshell->all_cmd);
    }
    free(mshell->line);
    free(mshell);
    return;
}
