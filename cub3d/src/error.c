/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:21:32 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/04 14:21:34 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/cub3D.h"

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

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
	{
		if (array[i] != NULL)
			free(array[i]);
		i++;
	}
	free(array);
}

static int free_map(t_board *board)
{
	if (board->mlx_ptr)
		free(board->mlx_ptr);
	if (board->win_ptr)
		free(board->win_ptr);
	if (board->no)
		free(board->no);
	if (board->so)
		free(board->so);
	if (board->we)
		free(board->we);
	if (board->ea)
		free(board->ea);
	if (board->c)
		free(board->c);
	if (board->f)
		free(board->f);
	if (board->map)
		free_array(board->map);
	free(board);
	exit(1);
}

int	ft_error(t_board *board, char *str, int i)
{
	ft_putstr_fd("Error\n", 2);
	if (str)
		ft_putstr_fd(str, STDERR_FILENO);
	if (i == 1)
		(free_map(board));
	/* else if (board)
		terminate_game(board); */
	exit(1);
}