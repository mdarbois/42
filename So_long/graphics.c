
#include "./include/so_long.h"

void	place_player(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->player, width * 40, height * 40);
	game->y_axis = height;
	game->x_axis = width;
}

void	place_collectable(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->collectable, width * 40, height * 40);
	game->collectables++;
}

void	place_images_in_game(t_game *game)
{
	int	i;
	int j;

	i = 64;
	j = 64;

	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "xpm/wall.xpm", &i, &j);
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr, "xpm/floor.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlx_ptr, "xpm/collectable.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "./xpm/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "xpm/exit.xpm", &i, &j);
	if (!game->wall || !game->floor || !game->collectable || !game->player || !game->exit)
	{
		ft_printf("Couldn't find a sprite. Does it exist?");
		exit_point(game);
	}
}

void	adding_in_graphics(t_game *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->height_map)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->wall, width * 40, height * 40);
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->exit, width * 40, height * 40);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->floor, width * 40, height * 40);
			width++;
		}
		height++;
	}
}