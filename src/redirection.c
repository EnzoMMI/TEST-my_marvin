/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-enzo.tiroumalle
** File description:
** redirection
*/

#include "minishell.h"

static char *rm_spaces(char *str)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;
    int y = 0;

    for (; str[i] != '\0'; ++i) {
        if (str[i] != ' ' && str[i] != '\t') {
            tmp[y] = str[i];
            ++y;
        }
    }
    tmp[y] = '\0';
    free(str);
    return tmp;
}

static void exe_redi(shell_t *mshell, char *name, char *tmp, int redi)
{
    int fd = 0;

    check_tab(mshell->tab);
    mshell->tab = my_str_to_word_array(tmp, " \t\n");
    if (redi == 2) {
        fd = open(name, O_WRONLY | O_CREAT | O_APPEND, 644);
        run_cmd(mshell);
    }
    if (redi == 1) {
        fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 644);
        run_cmd(mshell);
    }
    free(tmp);
    free(name);
}

int check_redirection(shell_t *mshell, int i)
{
    int redi = 0;
    char *name = NULL;
    char *tmp_n = NULL;
    char *tmp = NULL;

    for (int y = 0; mshell->all_cmd[i][y] != '\0'; ++y) {
        if (mshell->all_cmd[i][y] == '>' && mshell->all_cmd[i][y + 1] == '>')
            redi = 2;
        if (mshell->all_cmd[i][y] == '>' && mshell->all_cmd[i][y + 1] != '>')
            redi = 1;
    }
    if (redi == 0)
        return 0;
    check_tab(mshell->tab);
    mshell->tab = my_str_to_word_array(mshell->all_cmd[i], ">");
    tmp = my_strdup(mshell->tab[0]);
    tmp_n = my_strdup(mshell->tab[1]);
    name = rm_spaces(tmp_n);
    exe_redi(mshell, name, tmp, redi);
    return 1;
}
