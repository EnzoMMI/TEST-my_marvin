/*
** EPITECH PROJECT, 2022
** B-PSU-100-STG-1-1-sokoban-enzo.tiroumalle
** File description:
** unit_test
*/

#include "../src/minishell.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test, my_putchar, .init = redirect_all_std) {
    my_putchar('W');
    fflush(stdout);
    cr_assert_stdout_eq_str("W");
}

Test(test, my_putstr, .init = redirect_all_std) {
    my_putstr("Hello");
    fflush(stdout);
    cr_assert_stdout_eq_str("Hello");
}

Test(test, lib_functions) {
    char **tab = my_str_to_word_array("Hello World", " \n");
    char *str = my_strdup("enzo");
    char *str2 = my_strdup("AZERTY");
    str2 = my_strncpy(str2, str, 2);

    cr_assert_str_eq(str, "enzo");
    cr_assert_eq(my_strlen_bis("enzo", 'z'), 2);
    cr_assert_eq(my_strlen("enzo"), 4);
    str = my_strcat(str, "world");
    cr_assert_str_eq(str2, "enERTY");
    cr_assert_str_eq(tab[0], "Hello");
    cr_assert_str_eq(tab[1], "World");
    cr_assert_str_eq(str, "enzoworld");
    cr_assert_eq(my_strcmp("enzo", "enzo"), 0);
}

Test(test, mshell, .init = redirect_all_std) {
    char *argv[] = {"./mysh", "NULL"};
    char *env[] = {"test", "NULL"};

    shell_t *mshell = malloc(sizeof(shell_t));
    init_strcut(mshell, argv, env);
    mshell->line = "ls";
    run_cmd(mshell);
    cr_assert_eq(check_my_command(mshell), 1);
    fflush(stdout);
    cr_assert_stdout_eq_str("");
}
