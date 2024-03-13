/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** sokoban
*/

#include "src/minishell.h"

int main(int argc, char **argv, char **env)
{
    shell_t *mshell;
    int status = 0;

    if (argc != 1)
        return 84;
    mshell = malloc(sizeof(shell_t));
    init_strcut(mshell, argv, env);
    init_struct2(mshell, argv, env);
    status = my_getdata(mshell);
    free_struct(mshell);
    return status;
}
