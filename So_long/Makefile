SRCS = src/game_finish.c src/main.c src/map_control0.c src/msg_error.c\
	   src/player_movements.c src/put_image_to_window.c src/msg_error2.c\
	   src/take_image.c src/map_control1.c src/map_control2.c

SRCS_BONUS = ./bonus/write_screen.c

SRCS_MAND  = src/write_screen.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:./bonus/.c=.o)

CC = gcc

MFLAGS =  ./libft/libft.a ./mlx/libmlx.a ./ft_printf/libftprintf.a ./get_next_line/get_next_line.a

AFLAGS =  -Wall -Wextra -Werror -I./mlx -I./libft -I./ft_printf -I./get_next_line

RM = rm -rf

NAME = so_long

all :$(MFLAGS) $(NAME)

$(MFLAGS):
	make -C ./libft
	make -C ./get_next_line
	make -C ./ft_printf
	make -C ./mlx

$(NAME): $(OBJS) $(SRCS_MAND)
	$(CC) $(OBJS) $(MFLAGS) $(SRCS_MAND) $(CFLAGS) -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(MFLAGS) $(NAME)_bonus

$(NAME)_bonus : $(OBJS) $(OBJS_BONUS)
	$(CC) $(OBJS) $(MFLAGS) $(OBJS_BONUS) $(AFLAGS) -framework OpenGL -framework AppKit -o $(NAME)_bonus

fclean : clean
	$(RM) ./libft/*.a
	$(RM) ./src/*.a
	$(RM) ./ft_printf/*.a
	$(RM) ./get_next_line/*.a
#	make clean -C mlx
	$(RM) $(NAME)
	$(RM) $(NAME)_bonus

clean :
	$(RM) ./libft/*.o
	$(RM) ./src/*.o
	$(RM) ./ft_printf/*.o
	$(RM) ./get_next_line/*.o
	$(RM) ./bonus/write_screen.o

re : fclean all

.PHONY : all bonus fclean clean res
