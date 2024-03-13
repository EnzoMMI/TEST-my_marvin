/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** jsp
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int j = my_strlen(dest);

    for (int i = 0; src[i] != '\0'; i++, j++)
        dest[j] = src[i];
    dest[j] = '\0';
    return (dest);
}
