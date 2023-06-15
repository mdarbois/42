
SRCSSHELL = lexer/token_utils.c lexer/tokenization.c \
			command.c init.c main.c parser.c signals.c utils_list.c utils.c

LIBFT = libft

NAME = minishell

INCS = ./include

NAMELFT = libft.a

OBJS = $(SRCSSHELL:.c=.o)

.c.o: 
	cc -Wall -Wextra -Werror -c -I$(INCS) $< -o $(^:.c=.o) 

$(NAME): $(NAMELFT) $(OBJS)
	cc -Wall -Wextra -Werror $(SRCS) libft.a -o $(NAME)

$(NAMELFT):
	make -C $(LIBFT)

all: $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME) $(NAMELFT)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
