SRCS = src/ft_printf.c src/ft_conversions.c src/ft_convhex.c src/ft_convptr.c src/ft_convunsigned.c

DIRLIBFT = ./libft/

INCS = ./include/

LIBFT = libft

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

NAMELFT = libft.a

.c.o:
	cc -Wall -Wextra -Werror -c -I$(INCS) $< -o $(<:.c=.o)

$(NAME): $(NAMELFT) $(OBJS) 
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(NAMELFT):
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS) 
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus
