SRC =  	./interpreter/interpreter_process.c \
		./interpreter/interpreter_qoute.c \
		./interpreter/interpreter_return_value.c \
		./interpreter/interpreter_init.c \
		./interpreter/utils_interpreter.c \
		./parser/utils/strutils/ft_clearquotes.c \
		./parser/utils/strutils/ft_clearspace.c \
		./parser/utils/strutils/ft_free_strjoin.c \
		./parser/utils/strutils/ft_get_chrindex.c \
		./parser/utils/strutils/ft_get_next_word.c \
		./parser/utils/strutils/ft_get_qouteend.c \
		./parser/utils/strutils/ft_str_append.c \
		./parser/utils/utils.c \
		./parser/utils/utils_parser_array.c \
		./parser/utils/utils_parser_mem.c \
		./parser/utils/utils_parser_quote.c \
		./parser/utils/utils_parser_quote2.c \
		./parser/utils/utils_parser_split.c \
		./parser/utils/utils_parser_check_err.c \
		./parser/parser_process.c \


OBJS = $(SRC:.c=.o)

LIBFT = ../Libft/libft.a

NAME = minishell_parser.a

CFLAGS = -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

$(NAME) : $(OBJS)
	@make -sC ../Libft
	ar	-rcs $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make fclean -C ../Libft
	@rm -rf	./utils/*o
	@rm -rf	./parser/*o
	@rm -rf	./parser/utils/*o
	@rm -rf	./parser/utils/strutils/*o
	@rm -rf	./interpreter/*o
	@rm -rf	./*o


fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re all