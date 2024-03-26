NAME		= animal
SRC			= main.cpp	Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Animal.cpp Brain.cpp
OBJ			= $(SRC:.cpp=.o)
CXX			= c++
RM			= rm -rf
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re