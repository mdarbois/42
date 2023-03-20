/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:47:14 by mdarbois          #+#    #+#             */
/*   Updated: 2023/03/16 09:47:15 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_game
{
	int		fd;
	int		height;
	int		width;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;

	char	**map;

	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlx_ptr;
	void	*win_ptr;

}	t_game;

void	destroy(t_game *game, char *errmsg, int errnum);
void	die(char *errmsg, int errnum);
void	game_destroy(t_game *game);
int		map_reading(t_game *game, char **argv);
int		move(t_game *game, int i, int j);
void	graphics(t_game *game);
void	place_images(t_game *game);
void	print(t_game *game);
int		key_press(int command, t_game *game);
//int	key_press(int keycode, t_game *game);
//int	key_release(int keycode, t_game *game);
//int	destroy_hook(int keycode, t_game *game);
void	check_errors(t_game *game);
void	if_walls(t_game *game);
void	character_valid(t_game *game);
void	init(t_game *game);

#endif
