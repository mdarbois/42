SRCS = src/utils.c src/pipex.c src/ft_putendl_fd.c src/ft_putstr_fd.c \
		src/ft_split.c src/ft_strjoin.c src/ft_substr.c src/ft_strlen.c \
		src/ft_strlcpy.c src/ft_strdup.c

NAME = pipex

INCS = ./include

OBJS =  $(SRCS:.c=.o)

.c.o:
	cc -Wall -Wextra -Werror -c -I$(INCS) $< -o $(^:.c=.o)

$(NAME): $(NAMELFT) $(OBJS)
	cc -Wall -Wextra -Werror $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
