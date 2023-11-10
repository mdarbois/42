/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:45:48 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/11 16:45:49 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void init_board(t_board *board)
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
	board->flag = 0;
	board->width = 0;
	board->height = 0;
	board->map = NULL;
}

void print_struc(t_board *board)
{
	printf("board->no: %s", board->no );
	printf("board->so: %s", board->so);
	printf("board->we: %s", board->we);
	printf("board->ea: %s", board->ea);

	printf("board->width: %d\n", board->width);
	printf("board->height: %d\n", board->height);
 	int j;
	j = 0;
	if (board->f)
	{
	while (j < 3)
	{
		printf("board->f[%d]: %d\n", j, board->f[j]);
		j++;
	}
	}
	j = 0;
	if (board->c)
	{
	while (j < 3)
	{
		printf("board->c[%d]: %d\n", j, board->c[j]);
		j++;
	}
}
	j = 0;
	if (board->map)
	{
	while (board->map[j])
	{
		printf("board->map[%d]: %s", j, board->map[j]);
		j++;
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
			return (ft_error(NULL, "malloc init\n", 0));
	init_board(board);
	board->fd = open(argv[1], O_RDONLY);
	if (board->fd < 0)
		return (ft_error(board, "File doesn't exit\n", 1));
	
	map_reading(board); 
	print_struc(board);
	check_empty_lines(board);
	print_struc(board);
	check_identifier_factor(board->no);
	check_identifier_factor(board->so);
	check_identifier_factor(board->we);
	check_identifier_factor(board->ea);
 	check_map_walls(board); 
	print_struc(board);

}

