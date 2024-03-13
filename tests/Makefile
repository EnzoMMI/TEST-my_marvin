##
## EPITECH PROJECT, 2022
## B-PSU-100-STG-1-1-sokoban-enzo.tiroumalle
## File description:
## Makefile
##

SRC	=	$(shell find ../lib_functions/ -name "*.c")  \
		$(shell find ../src/ -name "*.c")  \
		$(shell find ./ -name "*.c")

OBJ	=	$(SRC:.c=.o)

NAME	=	../test

all:	$(OBJ)	$(NAME)

%.o: %.c
	$(CC) -c -g --coverage -o $@ $<

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) -lncurses -lcriterion --coverage
	rm $(OBJ)
	@echo "\033[01;38;5;10m================ Compiling: Done =======\
	=========\033[0;0m"

clean:	rm -f $(OBJ)
	@echo "\033[\033[1;33m================  Unit_test clean: Done =========\
	=======\033[0;0m"

fclean:
	rm -f $(NAME)
	@echo "\033[\033[0;31m================ Unit_test fclean: Done ==========\
	======\033[0;0m"

re:	fclean all

exe:	re
	$(shell echo ./binary Exemple d utilisation de ses propres regles)

.PHONY: re clean fclean all
