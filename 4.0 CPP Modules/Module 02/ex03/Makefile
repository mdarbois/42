SRCS = Fixed.cpp main.cpp bsp.cpp Point.cpp

INCS = Fixed.hpp Point.hpp

OBJS = $(SRCS:.cpp=.o)

NAME = a.out

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