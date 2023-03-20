/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:28:16 by mdarbois          #+#    #+#             */
/*   Updated: 2023/03/16 13:28:17 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

static int	horizontalwall(t_game *game)
{
	int	i;
	int	j;

	i = game->width;
	j = 0;
	while (j < i)
	{
		if (game->map[0][i] == '1' && game->map[game->height - 1][j] == '1')
			return (0);
		j++;
	}
	return (1);
}

static int	verticalwall(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->width;
	while (height < game->height)
	{
		if (!(game->map[height][0] == '1'
			&& game->map[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

void	if_walls(t_game *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	if (!verticalwalls || !horizontalwalls)
		destroy(game, "This map is missing the walls\n", 0);
}

static void	count_checker(t_game *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		ft_printf("Error Here!%c", game->map[height][width]);
		destroy(game, "\n", 0);
	}
	if (game->map[height][width] == 'C')
		game->columncount++;
	if (game->map[height][width] == 'P')
		game->playercount++;
	if (game->map[height][width] == 'E')
		game->exitcount++;
}

void	character_valid(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->height - 1)
	{
		width = 0;
		while (width <= game->width)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->columncount > 1
			&& game->exitcount == 1))
	{
		ft_printf("\nError\nSomething is wrong!\n");
		destroy(game, "either player, exit or collectable issue\n", 0);
	}
}
