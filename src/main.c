/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:02:32 by chustei           #+#    #+#             */
/*   Updated: 2023/09/28 17:43:37 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
/* #define BPP sizeof(int32_t)

int32_t	main(void)
{
	mlx_t* mlx = mlx_init(256, 256, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx_image_t* img = mlx_new_image(mlx, 128, 128);
	ft_memset(img->pixels, 255, img->width * img->height * BPP);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
} */

void	die(char *errmsg, int errnum)
{
	if (errmsg != 0 && errnum != 0)
		ft_putendl_fd("Error", 2);
	if (errmsg != 0)
		ft_putstr_fd(errmsg, 2);
	if (errmsg != 0 && errnum != 0)
		ft_putstr_fd(": ", 2);
	if (errnum != 0)
		ft_putstr_fd(strerror(errnum), 2);
	if (errmsg != 0 || errnum != 0)
	{
		ft_putendl_fd("", 2);
		exit(1);
	}
	exit(0);
}

 void init_board (t_board *board)
{
	board->mlx_ptr = NULL;
	board->win_ptr = NULL;
    board->map = NULL;
    board->no = NULL;
    board->so = NULL;
    board->we = NULL;
    board->ea = NULL;
    board->c = NULL;
    board->f = NULL;
   	board->fd = 0;
	board->width = 0;
	board->height = 0;

}

static void print_struc(t_board *board)
{
	printf("board->no: %s\n", board->no );
	printf("board->so: %s\n", board->so);
	printf("board->we: %s\n", board->we);
	printf("board->ea: %s\n", board->ea);
	printf("board->c: %s\n", board->c);
	printf("board->f: %s\n", board->f);
	printf("board->width: %d\n", board->width);
	printf("board->height: %d\n", board->height);
	int i;
	i = 0;
	while (board->map[i])
	{
		printf("board->map[%d]: %s", i, board->map[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	char	*sub;
	t_board	board;

	sub = ft_substr(argv[1], ft_strlen(argv[1]) - 4, 5);
	if (argc != 2)
		die("Invalid number of arguments!", 0);
	if (ft_strncmp(sub, ".cub", 5) != 0)
	{	
		free(sub);
		die("Invalid file type, use .cub!", 0);
	}
	free(sub);
	init_board(&board);
	/* ft_memset(&board, 0, sizeof(t_board)); */
	 map_reading(&board, argv);
	print_struc(&board);
/* 	check_identifier_c_f(board.c);
	check_identifier_c_f(board.f);
	check_identifier_factor(board.no);
	check_identifier_factor(board.so);
	check_identifier_factor(board.we);
	check_identifier_factor(board.ea);
	check_map_walls(&board); */

}

