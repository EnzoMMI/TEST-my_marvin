/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** minishell
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_
    #define MINISHELL
    #include "../lib_functions/my.h"

typedef struct {
    int error;
    int exit;
    char *line;
    char **tab;
    char *cmd;
    char *curr_path;
    int size_env;
    char **my_env;
    list_t *env;
    int tty;
    char **all_cmd;
} shell_t;

char *cp_word(char *, char *);
void init_strcut(shell_t *, char **, char **);
void init_struct2(shell_t *, char **, char **);
void free_struct(shell_t *);
int my_getdata(shell_t *);
int check_my_command(shell_t *);
int check_command(shell_t *);
void my_env(shell_t *);
void run_cmd(shell_t *);
void my_cd(shell_t *);
void my_setenv(shell_t *);
void my_unsetenv(shell_t *);
void my_exit(shell_t *);
int key_error(shell_t *);
void my_getenv(shell_t *, char **);
void l_env_to_tab(shell_t *);
void env_to_tab(shell_t *);
void change_env(shell_t *, char *);
char *cp_two_word(char *dest, char *, char *);
int exe_cmd(shell_t *);
int check_redirection(shell_t *, int);
void print_error(shell_t *);

#endif /* !MINISHELL_H_ */
