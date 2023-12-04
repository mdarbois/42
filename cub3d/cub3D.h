/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:54:22 by chustei           #+#    #+#             */
/*   Updated: 2023/09/28 17:32:53 by chustei          ###   ########.fr       */
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
    int width;
    int height;
}   t_board;

int check_identifier_factor(char *string);
int check_map_walls(t_board *board);
int check_map_characters(t_board *board);
int check_input(t_board *board, char **argv);
bool check_range(char *number);
int	extract_color(t_board *board, char *line);

void	die(char *errmsg, int errnum);
void	free_array(char **array);
int	ft_error(t_board *board, char *str, int i);

/* int identifier(t_board *board, char *line);*/
int check_color(t_board *board, char *string, int i, int type);
int	is_identifier(char *line, int j);
#endif
