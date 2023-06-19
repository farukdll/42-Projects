NAME	= libftprintf.a
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
ARFLAGS = -rcs
RM      = rm -rf

SRCS	= ft_printf.c ft_printf_utils.c
OBJS    = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
