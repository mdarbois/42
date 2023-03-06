SRCS = src/algo_utils.c src/big_algo.c src/get.c src/list_utils.c src/push_swap.c \
	src/quick_sort.c src/small_sort.c src/utils.c \
	src/rules_swap.c src/rules_push.c src/rules_reverse_rotate.c src/rules_rotate.c \

LIBFT = libft

NAME = push_swap

INCS = ./include

NAMELFT = libft.a

OBJS =  $(SRCS:.c=.o)

.c.o:
	cc -Wall -Wextra -Werror -c -I$(INCS) $< -o $(^:.c=.o)

$(NAME): $(NAMELFT) $(OBJS)
	cc -Wall -Wextra -Werror $(SRCS) libft.a -o $(NAME)

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
