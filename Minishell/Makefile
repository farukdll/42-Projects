RED				=	"\033[0;31m"
GREEN			=	"\033[0;32m"
YELLOW			=	"\033[0;33m"
CYAN			=	"\033[0;35m"
BLUE			=	"\033[0;36m"
WHITE			=	"\033[0;37m"
END				=	"\033[0;0m"
# Files
NAME	=	minishell
CC		=	gcc -ggdb
SRCS	=	allocate_files.c \
build_redirection.c \
build_command.c \
build_quote.c \
cmd_utils.c \
execute.c \
execute_utils.c \
heredoc.c \
main.c \
redirection.c \
signal.c \
utils.c \
utils_cleaning.c \
utils_list_del_list.c \
utils_list_del_structs.c \
utils_list_new.c \
utils_tree_new.c \
utils2.c \
redirection2.c \
execute2.c \
build_redirection2.c

OBJS 			= $(SRCS:.c=.o)
READLINE		= lib/readline
CFLAGS			= -Wall -Wextra -Werror -I./lib/lib/readline/include/
LFLAGS			= -L./lib/lib/readline/lib -lreadline
LIBFT			= libft/libft.a
PARSER 			= Parser/minishell_parser.a
BUILTINS 		= Builtins/minishell_builtins.a

all: $(NAME)

$(READLINE):
	make -C lib

$(LIBFT):
	@echo $(YELLOW) "Compiling..." Libft $(END)
	make -C Libft

$(PARSER):
	make -C ./Parser

$(BUILTINS):
	make -C ./Builtins

.c.o: $(READLINE)
	$(CC)  -c  $< $(CFLAGS)


$(NAME): $(READLINE) $(BUILTINS) $(LIBFT) $(PARSER) $(OBJS)
	@echo $(YELLOW) "Building... $(NAME)" $(END)
	$(CC) $(LFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(BUILTINS) $(PARSER)
	@echo $(GREEN) "$(NAME) created successfully!\n" $(END)

clean:
	@make -C ./Libft fclean
	@make -C ./Builtins fclean
	@make -C ./Parser fclean
	rm -rf $(OBJS)

fclean: clean
	@make -C lib fclean
	rm -rf ./minishell

re: clean all

norm :
	@norminette *.c
	@norminette ./Parser
	@norminette ./Builtins
	@norminette ./Libft

.PHONY: all, clean, fclean, re
