/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:27:56 by mdarbois          #+#    #+#             */
/*   Updated: 2023/03/16 13:27:57 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	game_destroy(t_game *game)
{
	int				i;

	if (game != 0)
	{
		if (game->map != 0)
		{
			i = 0;
			while (i < game->height)
				free(game->map[i++]);
			free(game->map);
		}
	}
}

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

void	destroy(t_game *game, char *errmsg, int errnum)
{
	if (game != 0)
	{
		if (game->floor != 0)
			mlx_destroy_image(game->mlx_ptr, game->floor);
		if (game->wall != 0)
			mlx_destroy_image(game->mlx_ptr, game->wall);
		if (game->collectable != 0)
			mlx_destroy_image(game->mlx_ptr, game->collectable);
		if (game->exit != 0)
			mlx_destroy_image(game->mlx_ptr, game->exit);
		if (game->player != 0)
			mlx_destroy_image(game->mlx_ptr, game->player);
		if (game->win_ptr != 0)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		if (game->mlx_ptr != 0)
			mlx_destroy_display(game->mlx_ptr);
		if (game->map != 0)
			game_destroy(game);
	}
	die(errmsg, errnum);
}

void	check_errors(t_game *game)
{
	if_walls(game);
	character_valid(game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	*sub;

	sub = ft_substr(argv[1], ft_strlen(argv[1]) - 4, 5);
	if (argc != 2)
		die("Invalid number of arguments!", 0);
	if (ft_strncmp(sub, ".ber", 5) != 0)
	{	
		free(sub);
		die("Invalid file type, user .ber!", 0);
	}
	free(sub);
	ft_memset(&game, 0, sizeof(t_game));
	map_reading(&game, argv);
	check_errors(&game);
	init(&game);
	place_images(&game);
	graphics(&game);
	mlx_key_hook(game.win_ptr, key_press, &game);
	mlx_hook(game.win_ptr, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlx_ptr);
}
