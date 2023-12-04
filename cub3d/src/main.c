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

 void init_board(t_board *board)
{

	board->mlx_ptr = NULL;
	board->win_ptr = NULL;
    board->no = NULL;
    board->so = NULL;
    board->we = NULL;
    board->ea = NULL;
    board->c = NULL;
    board->f = NULL;
   	board->fd = 0;
	board->width = 0;
	board->height = 0;
	board->map = NULL;
}

static void print_struc(t_board *board)
{
	printf("board->no: %s", board->no );
	printf("board->so: %s", board->so);
	printf("board->we: %s", board->we);
	printf("board->ea: %s", board->ea);
	printf("board->c: %s", board->c);
	printf("board->f: %s", board->f);
	printf("board->width: %d\n", board->width);
	printf("board->height: %d\n", board->height);
 	int i;
	i = 0;
	if (board->map)
	{
	while (board->map[i])
	{
		printf("board->map[%d]: %s", i, board->map[i]);
		i++;
	}
	} 
}

int main(int argc, char **argv)
{
	char	*sub;
	t_board	*board;

	sub = ft_substr(argv[1], ft_strlen(argv[1]) - 4, 5);
	if (argc != 2)
		die("Invalid number of arguments!", 0);
	if (ft_strncmp(sub, ".cub", 5) != 0)
	{	
		free(sub);
		die("Invalid file type, use .cub!", 0);
	}
	free(sub);
	board = malloc(sizeof(t_board));
	if (!board)
			return (ft_error(NULL, "Error\n", 0));
	init_board(board);
	print_struc(board);
/* 	check_input(board, argv);
 */	
	/*
	check_identifier_factor(board.no);
	check_identifier_factor(board.so);
	check_identifier_factor(board.we);
	check_identifier_factor(board.ea);
	
 	check_map_walls(&board);  */
		

}

