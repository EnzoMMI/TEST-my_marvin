/*
** EPITECH PROJECT, 2021
** lib
** File description:
** jsp
*/

#ifndef MY_H
    #define MY_H
    #include "list/list.h"
    #include <stdarg.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <sys/wait.h>

void my_putchar(char c);
int my_putstr(char const *str);
char **my_str_to_word_array(char *str, char *delim);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char *s1, char *s2);
int my_strlen_bis(char const *str, char n);
int my_strlen(char const *str);
char *my_strncpy(char *dest , char const *src , int n);
void free_tab(char **tab);
char *my_strdup(char const *src);
int my_getnbr(char const *str);
int len_tab(char **tab);
int is_alpha(char c);
void check_tab(char **tab);

#endif /* MY_H */
