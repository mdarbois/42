SRCS = Zombie.cpp zombieHorde.cpp main.cpp

INCS = Zombie.hpp

OBJS = $(SRCS:.cpp=.o)

NAME = zombies

FLAGS = -Wall -Wextra -Werror -std=c++98

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