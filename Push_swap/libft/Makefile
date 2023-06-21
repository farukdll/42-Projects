SRC =	ft_atoi.c			\
		ft_memcpy.c			\
		ft_memmove.c		\
		ft_split.c			\
		ft_strdup.c			\
		ft_strlen.c			\
		ft_substr.c			

OBJ		=	$(SRC:.c=.o)
CC		=	gcc
RM		=	rm -f
AR		=	ar -rcs
FLS		=	-Wall -Wextra -Werror
NAME	=	libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

.c.o:
	@$(CC) $(FLS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re:	fclean all
	

.PHONY: all $(NAME) clean fclean re

