/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-BSQ-enzo.tiroumalle
** File description:
** my_strlen_bis
*/

int my_strlen_bis(char const *str, char n)
{
    int len = 0;

    for (int i = 0; str[i] != n && str[i] != '\0'; i++)
        len = len + 1;
    return len;
}
