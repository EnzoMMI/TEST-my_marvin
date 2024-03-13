/*
** EPITECH PROJECT, 2021
** strncpy
** File description:
** jsp
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int j = 0;

    for (; j != n; j++)
        dest[j] = src[j];
    return (dest);
}
