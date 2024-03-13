/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-enzo.tiroumalle
** File description:
** env
*/

#include "minishell.h"

void my_unsetenv(shell_t *mshell)
{
    list_t *tmp = mshell->env;
    mshell->error = 1;

    if (len_tab(mshell->tab) != 2)
        return;
    for (; tmp != NULL &&
    my_strcmp(tmp->name, mshell->tab[1]) != 0; tmp = tmp->next);
    if (tmp != NULL) {
        if (mshell->my_env != NULL) {
            free_tab(mshell->my_env);
            free(mshell->my_env);
        }
        free_node(&mshell->env, mshell->tab[1]);
        mshell->size_env = list_len(mshell->env);
        l_env_to_tab(mshell);
        mshell->error = 0;

    }
    return;
}

void my_env(shell_t *mshell)
{
    for (int i = 0; mshell->my_env[i] != NULL; ++i) {
        my_putstr(mshell->my_env[i]);
        my_putchar('\n');
    }
    mshell->error = 0;
    return;
}
