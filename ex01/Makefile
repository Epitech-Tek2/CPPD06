##
## EPITECH PROJECT, 2021
## B-CPP-300-STG-3-1-CPPD17-clement.muth
## File description:
## Makefile
##

GCC	=	g++
CFLAGS	=	-Wall -Wextra -Werror -g

SRC	=	tmp_cnv.cpp

OBJ	=	$(SRC:.cpp=.o)
EXEC	=	my_convert_temp

all:	$(EXEC)

$(EXEC):	$(OBJ)
	$(GCC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(EXEC)

re:	fclean all

tests_run:
	gcc  */**/*.c tests/*/**/*.c -o unit_tests --coverage -lcriterion
	- ./unit_tests

.PHONY:	clean fclean re all