/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-enzo.tiroumalle
** File description:
** setenv
*/

#include "minishell.h"

static int error_env(shell_t *mshell, int tab_len)
{
    if (tab_len == 1) {
        my_env(mshell);
        return 1;
    }
    for (int i = 0; mshell->tab[1][i] != '\0'; ++i) {
        if (is_alpha(mshell->tab[1][i]) == 1) {
            mshell->error = 1;
            my_putstr("setenv: Variable name must");
            my_putstr(" contain alphanumeric characters.\n");
            return 1;
        }
    }
    if (mshell->my_env != NULL) {
        free_tab(mshell->my_env);
        free(mshell->my_env);
        return 0;
    }
}

void change_env(shell_t *mshell, char *v)
{
    v = malloc(sizeof(char) * (my_strlen(mshell->tab[2]) + 1));
    v = cp_word(v, mshell->tab[2]);
    change_node_value(&mshell->env, mshell->tab[1], v);
}

static void add_env(shell_t *mshell, int len, char *n, char *v)
{
    n = malloc(sizeof(char) * (my_strlen(mshell->tab[1]) + 1));
    n = cp_word(n, mshell->tab[1]);
    if (len == 2) {
        v = malloc(sizeof(char) * 1);
        v = cp_word(v, "\0");
    } else {
        v = malloc(sizeof(char) * (my_strlen(mshell->tab[2]) + 1));
        v = cp_word(v, mshell->tab[2]);
    }
    add_node(&mshell->env, n, v);
}

void my_setenv(shell_t *mshell)
{
    list_t *tmp = mshell->env;
    int tab_len = len_tab(mshell->tab);
    char *n = NULL;
    char *v = NULL;

    if (error_env(mshell, tab_len) == 1)
        return;
    mshell->error = 1;
    for (; tmp != NULL &&
    my_strcmp(tmp->name, mshell->tab[1]) != 0; tmp = tmp->next);
    if (tmp == NULL) {
        add_env(mshell, tab_len, n, v);
        mshell->error = 0;
    } else if (tab_len == 4 && my_getnbr(mshell->tab[3]) != 0) {
        change_env(mshell, v);
        mshell->error = 0;
    }
    mshell->size_env = list_len(mshell->env);
    l_env_to_tab(mshell);
    return;
}
