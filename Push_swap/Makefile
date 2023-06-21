NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = main.c rules.c rules2.c push_swap_utils.c sort.c free_error.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
		make -C libft
		$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME) 

clean:	
		make clean -C Libft
		$(RM) $(OBJ)

fclean:	clean
		make fclean -C Libft
		$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
