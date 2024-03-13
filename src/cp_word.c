/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-enzo.tiroumalle
** File description:
** cp_word
*/

#include "minishell.h"

char *cp_two_word(char *dest, char *src1, char *src2)
{
    int i = 0;

    for (int j = 0; src1[j] != '\0'; i++) {
        dest[i] = src1[j];
        ++j;
    }
    for (int j = 0; src2[j] != '\0'; i++) {
        dest[i] = src2[j];
        ++j;
    }
    dest[i] = '\0';
    return dest;
}

char *cp_word(char *dest, char *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
