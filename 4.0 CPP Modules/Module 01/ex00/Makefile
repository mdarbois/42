SRCS = Zombie.cpp newZombie.cpp randomChum.cpp main.cpp

INCS = Zombie.hpp

OBJS = $(SRCS:.cpp=.o)

NAME = zombie

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