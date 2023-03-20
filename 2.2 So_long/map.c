/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:27:50 by mdarbois          #+#    #+#             */
/*   Updated: 2023/03/16 13:27:50 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == 0)
		destroy(game, "mlx_init: can't load mlx", 0);
	game->win_ptr = mlx_new_window(game->mlx_ptr, (game->width * 40),
			(game->height * 40), "solong");
	if (game->win_ptr == 0)
		destroy(game, "mlx_new_window: can't create a window", 0);
}

void	print(t_game *game)
{
	char	*nb_counter;
	char	*nb_collectables;

	mlx_string_put(game->mlx_ptr, game->win_ptr, 10,
		10, 0xFFc0cb, "Movements: ");
	nb_counter = ft_itoa(game->counter);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 140,
		10, 0xFFc0cb, nb_counter);
	free(nb_counter);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10,
		30, 0xFFc0cb, "Collectables Remaining: ");
	nb_collectables = ft_itoa(game->collectables);
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		180, 30, 0xFFc0cb, nb_collectables);
	free(nb_collectables);
	nb_counter = NULL;
	nb_collectables = NULL;
}

static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_game *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->height++;
	temporary = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!temporary)
		destroy(0, "init: malloc", errno);
	temporary[game->height] = NULL;
	while (i < game->height - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	temporary[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	return (1);
}

int	map_reading(t_game *game, char **argv)
{
	char	*readmap;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!add_line(game, readmap))
			break ;
	}
	close (game->fd);
	game->width = width_of_map(game->map[0]);
	return (1);
}
