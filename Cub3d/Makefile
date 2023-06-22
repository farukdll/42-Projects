CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -Imlx
NAME			=	cub3D
RM				=	rm -rf
LMLX_M			=	-Lmlx -lmlx -framework OpenGL -framework AppKit
SOURCE			=	main.c mapcheck.c \
					function.c function2.c function3.c \
					button_assignment.c key_move.c \
					mapread.c mapread2.c mapread3.c mapread4.c mapread5.c mapread6.c mapread7.c\
					game_build.c wall_image_making.c \
					set_zero.c set_zero2.c\
					playerloc.c raycasting_init.c \
					
					

MLXM	=	 $(C_MLXD) $(LMLX_M)

OBJECT			=	$(SOURCE:.c=.o)

C_MLXC			=	./mlx/
C_MLXD			=	./mlx/libmlx.a
					
all: 				$(NAME)

$(NAME):			$(OBJECT)
					@echo "$(YELLOW)Compiling...$(END)"
					@$(MAKE) -C $(C_MLXC)
					@$(CC) $(CFLAGS) $(OBJECT) $(MLXM) -o ${NAME}
					@echo "$(GREEN)===> Game ready to start <===$(END)"	

%.o:		%.c
					@echo "$(YELLOW)Compiling...$(END)"
					$(CC) -c $(CFLAGS) -o $@ $<
					@printf "$(GREEN)"
					
clean: 				
					$(MAKE) -C $(C_MLXC) clean
					${RM} $(OBJECT)

fclean: 			clean
					$(MAKE) -C $(C_MLXC) clean
					$(RM) $(C_MLXD)
					${RM} $(NAME)
					@echo "$(RED)===> Cub3D & Mlx Cleaned <===$(END)"
					@echo "$(RED)===> DONE <===$(END)"

re:					fclean $(NAME)

.PHONY:				all clean fclean re bonus

##############______________Colors______________##############

END				=	\033[0m
GREEN			=	\033[1;32m
YELLOW			=	\033[1;33m
BLUE			=	\033[1;34m
RED				=	\033[1;31m