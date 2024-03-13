/*
** EPITECH PROJECT, 2022
** B-CPE-100-STG-1-1-cpoolday04-enzo.tiroumalle
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++)
        ++len;
    return len;
}
