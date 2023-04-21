NAME = philo

FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=thread

INCS = include/philo.h 

SRCS = end.c init.c main.c routine.c threads.c utils.c

OBJS = $(SRCS:.c=.o)

THREAD_FLAGS = -lpthread

.c.o:
	cc $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) $(THREAD_FLAGS) -o $(NAME)

clean:
	rm -r $(OBJS)

fclean: clean
	rm -r $(NAME)

re:
	fclean all	

.PHONY:		all clean fclean re
