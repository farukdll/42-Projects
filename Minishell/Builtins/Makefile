SOURCES			=	command_env.c command_export.c command_unset.c command_exit.c
SOURCES			+=	command_cd.c command_echo.c command_pwd.c utils_free.c
SOURCES			+=	utils_export_unset.c utils.c ft_sort_params.c export_quote.c

LIBFT	=	../Libft/libft.a

OBJECTS			= $(SOURCES:.c=.o)

CC			= gcc
RM			= rm -rf
AR			= ar rcs
CFLAGS		= -g
NAME		= minishell_builtins.a

all: $(LIBFT) $(NAME)

$(LIBFT) :
	make -C ../Libft

$(NAME): $(OBJECTS)
	#gcc $(CFLAGS) main.c $(SOURCES) $(LIBFT) -o debug
	@$(AR) $(NAME) $(OBJECTS)
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
