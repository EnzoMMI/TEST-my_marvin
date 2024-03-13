##
## EPITECH PROJECT, 2021
## delivery
## File description:
## Makefile
##

SRC	=	$(shell find lib_functions/ -name "*.c")  \
		$(shell find src/ -name "*.c")  \
		minishell.c

OBJ	=	$(SRC:.c=.o)

TESTS = tests/

NAME	=	mysh

all:	$(OBJ)	$(NAME)

%.o: %.c
	$(CC) -c -g -o $@ $<

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) -g -lncurses
	@echo "\033[01;38;5;10m================ Compiling: Done =======\
	=========\033[0;0m"

clean:
	rm -f $(OBJ)
	@echo "\033[\033[1;33m================  clean: Done =========\
	=======\033[0;0m"

fclean:		clean
	rm -f $(NAME)
	@echo "\033[\033[0;31m================ fclean: Done ==========\
	======\033[0;0m"

re:	fclean all

exe:	re
	$(shell echo ./binary Exemple d utilisation de ses propres regles)

tests_run:	clean
	make -C $(TESTS)
	./test

clean_test: clean
	$(shell find . -type f -name '*.gcda' -delete)
	$(shell find . -type f -name '*.gcno' -delete)
	make clean -C $(TESTS)

fclean_test:	fclean
	$(shell find . -type f -name '*.gcda' -delete)
	$(shell find . -type f -name '*.gcno' -delete)
	make fclean -C $(TESTS)

re_test:
	make re -C $(TESTS)

.PHONY: re clean fclean all
