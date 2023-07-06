SRCS = main.c init.c signals.c lexer.c token.c token_utils.c utils_list_lexer.c \
		utils.c utils_list_parser.c free.c io.c quotes.c parser.c parser_utils.c \
		opens.c heredoc_utils.c expansion_heredoc.c expansion_var.c \
		expansion_utils.c execute.c builtins_exit.c pipex.c \
		execute_utils.c env.c builtins_unset.c builtins_pwd.c \
		builtins_export.c builtins_env.c builtins_echo.c builtins_cd.c fds.c \
		parse_args.c parse_args_echo.c 
		
LIBFT = libft

NAME = minishell

INCS = ./include

NAMELFT = libft.a

OBJS =  $(SRCS:.c=.o)

FLAGS =  -Wall -Wextra -Werror -g3 -fsanitize=address

.c.o:
	cc $(FLAGS) -c -I$(INCS) $<  -I /usr/local/opt/readline/include -o $(^:.c=.o)

$(NAME): $(NAMELFT) $(OBJS)
	cc $(FLAGS) $(SRCS) libft.a -lreadline -L /usr/local/opt/readline/lib -o $(NAME)

$(NAMELFT):
	make -C $(LIBFT)
	cp libft/libft.a .

all: $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME) $(NAMELFT)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
