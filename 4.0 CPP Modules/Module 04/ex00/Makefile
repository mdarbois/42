SRCS = Animal.cpp main.cpp Cat.cpp Dog.cpp WrongCat.cpp WrongAnimal.cpp

INCS = Animal.hpp Cat.hpp Dog.hpp WrongCat.hpp WrongAnimal.hpp

OBJS = $(SRCS:.cpp=.o)

NAME = ex00

FLAGS = -g -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $@ -I .

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re