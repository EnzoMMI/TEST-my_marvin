/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-enzo.tiroumalle
** File description:
** getenv
*/

#include "minishell.h"

static char *create_str(list_t *tmp, char *dest)
{
    int i = 0;

    for (int y = 0; tmp->name[y] != '\0'; ++y) {
        dest[i] = tmp->name[y];
        ++i;
    }
    dest[i] = '=';
    ++i;
    for (int y = 0; tmp->value[y] != '\0'; ++y) {
        dest[i] = tmp->value[y];
        ++i;
    }
    dest[i] = '\0';
    return dest;
}

void l_env_to_tab(shell_t *mshell)
{
    mshell->my_env = malloc(sizeof(char *) * (mshell->size_env + 1));
    list_t *tmp = mshell->env;
    int i = 0;
    int len = 0;

    for (; i != mshell->size_env; ++i) {
        len = my_strlen(tmp->name) + my_strlen(tmp->value);
        mshell->my_env[i] = malloc(sizeof(char) * (len + 2));
        mshell->my_env[i] = create_str(tmp, mshell->my_env[i]);
        tmp = tmp->next;
    }
    mshell->my_env[i] = NULL;
}

static void getname(shell_t *mshell, char *str)
{
    char *n = malloc(sizeof(char) * my_strlen(str));
    char *v = malloc(sizeof(char) * my_strlen(str));
    int i = 0;

    for (; str[0] != '='; str++) {
        n[i] = str[0];
        ++i;
    }
    ++str;
    n[i] = '\0';
    v = cp_word(v, str);
    add_node(&mshell->env, n, v);
}

void my_getenv(shell_t *mshell, char **env)
{
    for (int i = 0; env[i] != NULL; ++i)
        getname(mshell, env[i]);
    mshell->size_env = list_len(mshell->env);
    l_env_to_tab(mshell);
}
