/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** getdata
*/

#include "minishell.h"

static void check_bin_comp(shell_t *mshell, int status)
{
    if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
        my_putstr(mshell->tab[0]);
        my_putstr(": Exec format error. Wrong Architecture.\n");
        return;
    }
    print_error(mshell);
}

static void check_segv(shell_t *mshell, int status)
{
    if (WTERMSIG(status) == 8 && WCOREDUMP(status) == 0) {
        my_putstr("Floating exception\n");
        return;
    } else if (WTERMSIG(status) == 8 && WCOREDUMP(status) != 0) {
        my_putstr("Floating exception (core dumped)\n");
        return;
    }
    if (WTERMSIG(status) == SIGSEGV && WCOREDUMP(status) != 0) {
        my_putstr("Segmentation fault (core dumped)\n");
        return;
    } else if (WTERMSIG(status) == SIGSEGV) {
        my_putstr("Segmentation fault\n");
        return;
    }
}

void run_cmd(shell_t *mshell)
{
    int STATUS = 0;
    pid_t pid;

    if (key_error(mshell) == 0)
        return;
    if (check_my_command(mshell) == 0)
        return;
    pid = fork();
    if (pid == -1)
        exit(1);
    else if (pid == 0)
        check_command(mshell);
    else {
        waitpid(pid, &STATUS, 0);
        WIFSIGNALED(STATUS) ? check_segv(mshell, STATUS) : '0';
        check_bin_comp(mshell, STATUS);
        mshell->error = WEXITSTATUS(STATUS);
    }
}

static void run_all_cmd(shell_t *mshell)
{
    check_tab(mshell->all_cmd);
    mshell->all_cmd = my_str_to_word_array(mshell->line, ";\n");

    for (int i = 0; mshell->all_cmd[i] != NULL; ++i) {
        check_tab(mshell->tab);
        mshell->tab = my_str_to_word_array(mshell->all_cmd[i], " \t\n");
        if (check_redirection(mshell, i) == 0)
            run_cmd(mshell);
    }
}

int my_getdata(shell_t *mshell)
{
    ssize_t nread = 0;
    size_t len = 0;
    char *line = NULL;

    while (mshell->exit == 0) {
        mshell->tty ? my_putstr("$> ") : '0';
        nread = getline(&line, &len, stdin);
        if (nread == -1)
            break;
        mshell->line = line;
        if (mshell->line[0] == 4)
            break;
        run_all_cmd(mshell);
    }
    return mshell->error;
}
