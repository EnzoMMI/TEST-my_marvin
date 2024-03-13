/*
** EPITECH PROJECT, 2021
** strcmp
** File description:
** jsp
*/

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    for (; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++);
    return (s1[i] - s2[i]);
}
