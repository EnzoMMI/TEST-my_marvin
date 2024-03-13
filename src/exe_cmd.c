/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-enzo.tiroumalle
** File description:
** exe_cmd
*/

#include "minishell.h"

static void check_with_patch(shell_t *mshell, char *path, char *cmd_tmp)
{
    cmd_tmp = malloc(sizeof(char) * (my_strlen(path) + 2));
    cmd_tmp = cp_two_word(cmd_tmp, path, "/");
    mshell->cmd = malloc(sizeof(char) *
    (my_strlen(cmd_tmp) + my_strlen(mshell->tab[0]) + 1));
    mshell->cmd = cp_two_word(mshell->cmd, cmd_tmp, mshell->tab[0]);
}

static int check_in_path(shell_t *mshell)
{
    struct stat st;
    list_t *tmp = mshell->env;
    char **path = NULL;
    char *cmd_tmp = NULL;

    for (; tmp != NULL &&
    my_strcmp(tmp->name, "PATH") != 0; tmp = tmp->next);
    if ( tmp == NULL)
        return 1;
    path = my_str_to_word_array(tmp->value, ":");
    for (int i = 0; path[i] != NULL; ++i) {
        check_with_patch(mshell, path[i], cmd_tmp);
        free(cmd_tmp);
        if (stat(mshell->cmd, &st) != -1)
            return S_ISREG(st.st_mode) ? 0 : '0';
    }
    return 1;
}

void print_error(shell_t *mshell)
{
    mshell->error = 1;
    my_putstr(mshell->tab[0]);
    my_putstr(": Command not found.\n");
}

int exe_cmd(shell_t *mshell)
{
    mshell->error = 0;
    struct stat st;

    if (stat(mshell->tab[0], &st) != -1 && S_ISREG(st.st_mode)) {
        if (execve(mshell->tab[0], mshell->tab, mshell->my_env) != 0) {
            mshell->error = 1;
            return 1;
        } else
            return 0;
    }
    if (check_in_path(mshell) == 0) {
        if (execve(mshell->cmd, mshell->tab, mshell->my_env) != 0) {
            mshell->error = 1;
            return 1;
        } else
            return 0;
    }
    return 1;
}
