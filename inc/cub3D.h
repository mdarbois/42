/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:44:58 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/11 16:44:59 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/include/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

# include <fcntl.h>
# include <errno.h>
# include <string.h>

# define WIDTH 512
# define HEIGHT 512

typedef struct s_board
{
	void	*mlx_ptr;
	void	*win_ptr;
	char **map;
	char *no;
	char *so;
	char *we;
	char *ea;
	int *c;
	int *f;
	int fd;
	int flag;
	int width;
	int height;
}   t_board;

int		map_reading(t_board *board);
int 	check_color(t_board *board, char *string, int i, int type);
int		is_identifier(char *line, int j);
int		select_identifier(t_board *board, char *line);


int 	check_empty_lines(t_board *board);
int 	check_identifier_factor(char *string);
int 	check_map_walls(t_board *board);



void 	print_struc(t_board *board);


void	die(char *errmsg, int errnum);
void	free_array(char **array);
int		ft_error(t_board *board, char *str, int i);



#endif
