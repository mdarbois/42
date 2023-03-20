
NAME = so_long

FLAGS = -Wall -Wextra -Werror

INCS = include/so_long.h 

SRCS = errors.c event.c graphics.c main.c map.c move.c

OBJS = $(SRCS:.c=.o)

MLX_FLAGS = -lXext -lX11
#MLX_FLAGS = -Lminilibx-mac -lmlx -framework OpenGL -framework AppKit

MINILIBX_PATH = minilibx-linux/
#MINILIBX_PATH = minilibx-mac/

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
