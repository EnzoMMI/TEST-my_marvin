/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-enzo.tiroumalle
** File description:
** is_alpha
*/

#include "my.h"

int is_alpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return 0;
    if (c >= 'A' && c <= 'Z')
        return 0;
    if (c >= '0' && c <= '9')
        return 0;
    return 1;
}
