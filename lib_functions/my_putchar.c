/*
** EPITECH PROJECT, 2022
** B-CPE-110-STG-1-1-BSQ-enzo.tiroumalle
** File description:
** my_putchar
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
