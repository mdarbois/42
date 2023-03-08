
NAME = so_long

FLAGS = -Wall -Wextra -Werror

INCS = include/so_long.h 

SRCS = end.c errors.c event.c graphics.c init.c map_parsing.c map.c mlx_utils.c moves.c main.c update.c

OBJS = $(SRCS:.c=.o)

MLX_FLAGS = -lXext -lX11

MINILIBX_PATH = minilibx-linux/

FT_PRINTF_PATH = ft_printf/

LIBFT_PATH = libft/

.c.o:
	cc $(FLAGS) -c $< -o $@

all: $(NAME)

lib:
	make -C $(LIBFT_PATH)

mlx:
	make -sC $(MINILIBX_PATH)

$(NAME): lib mlx  $(OBJS)
	cc $(FLAGS) $(OBJS) $(LIBFT_PATH)libft.a $(MINILIBX_PATH)libmlx.a $(MLX_FLAGS) -o $(NAME)

clean:
	rm -r $(OBJS)

fclean: clean
	rm -r $(NAME)

re:
	fclean all	

.PHONY:		all clean fclean re
