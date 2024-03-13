/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-enzo.tiroumalle
** File description:
** list
*/

#ifndef LIST_H_
    #define LIST_H_

typedef struct cell_t{
    char *name;
    char *value;
    struct cell_t *next;
}list_t, cell_t;

list_t *create_node(char *, char *);
void add_node(list_t **, char *, char *);
void free_list(list_t *);
int list_len(list_t *);
void free_node(list_t **, char *);

void change_node_value(list_t **head, char *name, char *value);

#endif /* !LIST_H_ */
