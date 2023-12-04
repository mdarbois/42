NAME	= cub3D
CFLAGS	= -Wextra -Wall -Werror -g3
LIBMLX	= ./lib/minilibx-linux
MLX_FLAGS = -lXext -lX11
LIBFT	= ./lib/libft

HEADERS	= -I ./inc/ -I $(LIBMLX)/include -I $(LIBFT)/inc
LIBS	= $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	= src/main.c src/check.c src/map.c src/error.c src/check_walls.c src/check_colors.c

OBJS	= ${SRCS:.c=.o}

all: libft libmlx $(NAME)

libft:
		make -C $(LIBFT)

libmlx:
	make -sC $(LIBMLX)

%.o: %.c
	cc $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): libft libmlx $(OBJS)
	cc $(CFLAGS) $(OBJS) $(LIBFT)/libft.a $(LIBMLX)/libmlx.a $(MLX_FLAGS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -fr $(LIBMLX)/build
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
