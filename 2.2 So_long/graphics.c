/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:28:01 by mdarbois          #+#    #+#             */
/*   Updated: 2023/03/16 13:28:03 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

static void	place_player(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->player, width * 40, height * 40);
	game->y_axis = height;
	game->x_axis = width;
}

static void	place_collectable(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->collectable, width * 40, height * 40);
	game->collectables++;
}

void	place_images(t_game *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"xpm/floor.xpm", &i, &j);
	if (game->floor == 0)
		destroy(game, "place images: can't load floor", 0);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"xpm/wall.xpm", &i, &j);
	if (game->wall == 0)
		destroy(game, "place images: can't load wall", 0);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"xpm/player.xpm", &i, &j);
	if (game->player == 0)
		destroy(game, "place images: can't load player", 0);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"xpm/exit.xpm", &i, &j);
	if (game->exit == 0)
		destroy(game, "place images: can't load exit", 0);
	game->collectable = mlx_xpm_file_to_image(game->mlx_ptr,
			"xpm/collectable.xpm", &i, &j);
	if (game->collectable == 0)
		destroy(game, "place images: can't load collectable", 0);
}

static void	put_image(t_game *game, int width, int height, char c)
{
	if (c == '1')
	{
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->wall, width * 40, height * 40);
	}
	if (c == 'E')
	{
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->exit, width * 40, height * 40);
	}
	if (c == '0')
	{
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->floor, width * 40, height * 40);
	}
}

void	graphics(t_game *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				put_image(game, width, height, '1');
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			if (game->map[height][width] == 'E')
				put_image(game, width, height, 'E');
			if (game->map[height][width] == '0')
				put_image(game, width, height, '0');
			width++;
		}
		height++;
	}
}
