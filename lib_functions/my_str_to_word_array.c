/*
** EPITECH PROJECT, 2022
** B-PSU-101-STG-1-1-minishell1-enzo.tiroumalle
** File description:
** my_str_to_word_array
*/

#include "my.h"

static int is_in(char c, char *dict)
{
    for (int i = 0; dict[i]; i++) {
        if (c == dict[i])
            return 1;
    }
    return 0;
}

static int my_world_len(char *str, char *delimitors)
{
    int word_len = 0;

    for (int i = 0; str[i] && !is_in(str[i], delimitors); i++) {
        word_len++;
    }
    return word_len;
}

static int my_count_words(char *str, char *delimitors)
{
    int nb_words = 0;

    while (str[0]) {
        while (str[0] && is_in(str[0], delimitors)) {
            str++;
        }
        if (str[0])
            nb_words++;
        while (str[0] && !is_in(str[0], delimitors)) {
            str++;
        }
    }
    return nb_words;
}

char **my_str_to_word_array(char *str, char *delim)
{
    int nb_words = my_count_words(str, delim);
    char **tab = malloc(sizeof(char *) * (nb_words + 1));
    int word_len = 0;

    for (int i = 0; i != nb_words; i++) {
        while (*str && is_in(*str, delim))
            str++;
        word_len = my_world_len(str, delim);
        tab[i] = malloc(sizeof(char) * (word_len + 1));
        my_strncpy(tab[i], str, word_len);
        tab[i][word_len] = '\0';
        str += word_len;
        while (*str && is_in(*str, delim))
            str++;
    }
    tab[nb_words] = NULL;
    return tab;
}
