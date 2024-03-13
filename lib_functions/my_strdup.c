/*
** EPITECH PROJECT, 2022
** B-PSU-101-STG-1-1-minishell1-enzo.tiroumalle
** File description:
** my_str_to_word_array
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *new_str = malloc(sizeof(char) * my_strlen(src) + 1);
    int i = 0;

    for (; src[i] != '\0'; i++)
        new_str[i] = src[i];
    new_str[i] = '\0';
    return new_str;
}
