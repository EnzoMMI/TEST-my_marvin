/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-enzo.tiroumalle
** File description:
** my_cd
*/

#include "minishell.h"

static void check_file_or_dir(shell_t *mshell, char *path)
{
    struct stat st;

    if (stat(path, &st) != -1) {
        if (S_ISREG(st.st_mode)) {
            my_putstr(mshell->tab[1]);
            my_putstr(": Not a directory.\n");
        }
    } else {
        my_putstr(mshell->tab[1]);
        my_putstr(": No such file or directory.\n");
    }
    return;
}

static int cd_error(shell_t *mshell, char *dir)
{
    if (my_strcmp(dir, "-") == 0)
        chdir(mshell->curr_path);
    else if (chdir(dir) == -1) {
        mshell->error = 1;
        check_file_or_dir(mshell, dir);
        return 1;
    }
    return 0;
}

void my_cd(shell_t *mshell)
{
    char ancien_path[500];
    char *dir = mshell->tab[1];

    getcwd(ancien_path, sizeof(ancien_path));
    if (dir != NULL) {
        if (cd_error(mshell, dir) == 1)
            return;
    } else
        chdir("/home/main");
    mshell->curr_path != NULL ? free(mshell->curr_path) : '0';
    mshell->curr_path = my_strdup(ancien_path);
    mshell->error = 0;
    return;
}
