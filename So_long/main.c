#include "./include/so_long.h"

void	ft_destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->wall);
	mlx_destroy_image(game->mlx_ptr, game->floor);
	mlx_destroy_image(game->mlx_ptr, game->collectable);
	mlx_destroy_image(game->mlx_ptr, game->player);
	mlx_destroy_image(game->mlx_ptr, game->exit);
}

void	ft_free_all_allocated_memory(t_game *game)
{
	ft_destroy_images(game);
	exit_point(game);
	mlx_destroy_display(game);
	free(game->mlx_ptr);
	free(game);
}

int	exit_point(t_game *game)
{
	int	line;

	line = 0;
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	while (line < game->height_map - 1)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

int main (int argc, char **argv)
{
	t_game game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
	{
		ft_printf("Invalid number of arguments!");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(ft_substr(argv[1],ft_strlen(argv[1]) - 4, 5),".ber",5) != 0)
	{
		ft_printf("Invalid file type, user .ber!");
		exit(EXIT_FAILURE);
	}
	
	map_reading(&game, argv);
	
	check_errors(&game);

	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
	{
		ft_printf("Fails to start Minilibx");
		free(game.mlx_ptr);
		exit (EXIT_FAILURE);
	}
	game.win_ptr = mlx_new_window(game.mlx_ptr, (game.width_map * 40), (game.height_map * 40), "So Long");
	if (game.win_ptr == NULL)
	{
		ft_printf("Fails to create a new window");
		free(game.win_ptr);
		exit (EXIT_FAILURE);
	}
	
	place_images_in_game(&game);

	adding_in_graphics(&game);

	mlx_hook(game.win_ptr, 2, 1L<<0, key_press, &game);
	mlx_hook(game.win_ptr, 3, 1L<<1, key_release, &game);
	mlx_hook(game.win_ptr, 17, 0, exit_point, &game);

	mlx_loop(game.mlx_ptr);

	ft_free_all_allocated_memory(&game);
	return (0);
}