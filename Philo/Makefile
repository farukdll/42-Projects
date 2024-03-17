NAME = philo
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra -pthread 

SRCS = main.c whole_creat.c check_print_free.c argcheck_time.c eat_sleep_think.c

FLAGS_DATARACE = -fsanitize=thread -g

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

data_race:
	@$(CC) $(FLAGS_DATARACE) $(SRCS) -o $(NAME)

clean:
	@$(RM) $(NAME) *.dSYM

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re