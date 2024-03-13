/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-enzo.tiroumalle
** File description:
** env_to_tab
*/

#include "minishell.h"

void env_to_tab(shell_t *mshell)
{
    list_t *tmp = mshell->env;
    mshell->my_env = malloc(sizeof(char *) * (mshell->size_env + 1));
    int i = 0;

    for (; i != mshell->size_env; ++i) {
        mshell->my_env[i] = malloc(sizeof(char) * 500);
        mshell->my_env[i] = my_strdup(mshell->env->name);
        mshell->my_env[i] = my_strcat(mshell->my_env[i], mshell->env->name);
        mshell->my_env[i] = my_strcat(mshell->my_env[i], mshell->env->value);
    }
    mshell->my_env[i] = NULL;
}
