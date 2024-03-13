/*
** EPITECH PROJECT, 2021
** putsr
** File description:
** jsp
*/

#include "my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
