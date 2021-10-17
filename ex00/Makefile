##
## EPITECH PROJECT, 2021
## B-CPP-300-STG-3-1-CPPD17-clement.muth
## File description:
## Makefile
##

GCC	=	g++
CFLAGS	=	-Wall -Wextra -Werror -g

SRC	=	my_cat.cpp

OBJ	=	$(SRC:.cpp=.o)
EXEC	=	my_cat

all:	$(EXEC)

$(EXEC):	$(OBJ)
	$(GCC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(EXEC)

re:	fclean all

.PHONY:	clean fclean re all