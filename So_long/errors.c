
#include "./include/so_long.h"


static int	horizontal_wall(t_game *game)
{
	int	j;

	j = 0;
	while (j < game->width_map)
	{	
		if(game->map[0][j] != '1' || game->map[game->height_map-1][j] != '1')
				return(0);
		j++;
	}
	return(1);
}

static int	vertical_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height_map)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width_map - 1] != '1')
			return (0);
		i++;
	}
	return (1);
} 

static void	if_walls(t_game *game)
{
	int	v_walls;
	int	h_walls;

	v_walls = vertical_wall(game);
	h_walls = horizontal_wall(game);
	if (v_walls == 0 || h_walls == 0)
	{
		ft_printf("\nThis map is missing walls\n");
		exit_point(game);
	}
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
		ft_printf("\nError Here!%c\n", game->map[height][width]);
		exit_point(game);
	}
	if (game->map[height][width] == 'C')
			game->collcount++;
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
	while (height < game->height_map - 1)
	{
		width = 0;
		while (width <= game->width_map)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->collcount >= 1
			&& game->exitcount == 1))
	{
		ft_printf("\nError\nSomething is wrong!\n");
		exit_point(game);
	}
}

 void rectangle_map(t_game *game)
{
	int		y;
	int		x;
	int		count_x;

	x = 0;
	y = 0;
	count_x = 0;
	while (game->map[0][count_x])
		count_x++;
	while (game->map[y] != NULL)
	{
		while (game->map[y][x])
			x++;
		if (x != count_x)
		{
			ft_printf("Map must be rectangular\n");
			exit_point(game);
		}
		x = 0;
		y++;
	}
} 

void	check_errors(t_game *game)
{
	rectangle_map(game);
	if_walls(game);
	character_valid(game);
}