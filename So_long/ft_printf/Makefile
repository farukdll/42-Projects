SRCS = ft_printf_utils.c ft_printf.c

OBJS = $(SRCS:.c=.o)

CC = @gcc

RM = @rm -f

CFLAGS = -Wall -Wextra -Werror -I.

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re