SRCS			=	ft_split.c ft_strchr.c ft_substr.c ft_strlen.c\
				ft_strdup.c ft_strnstr.c ft_calloc.c ft_bzero.c\
				ft_strjoin.c ft_itoa.c ft_memset.c
				



OBJS			= $(SRCS:.c=.o)

CC				= @gcc

RM				= @rm -f

CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
