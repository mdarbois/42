
#include "./include/so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_point(game);
	if (keycode == 119)
		game->moves->player_up = 1;
	if (keycode == 115)
		game->moves->player_down = 1;
	if (keycode == 97)
		game->moves->player_left = 1;
	if (keycode == 100)
		game->moves->player_right = 1;
	adding_in_graphics(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == 119)
		game->moves->player_up = 0;
	if (keycode == 115)
		game->moves->player_down = 0;
	if (keycode == 97)
		game->moves->player_left = 0;
	if (keycode == 100)
		game->moves->player_right = 0;
	adding_in_graphics(game);
	return (0);
}

static void	had_move(t_game *game, int x, int y)
{
	char	*nb;
	if (game->moves->player.x != x || game->moves->player.y != y)
	{
		game->moves->player_move++;
		//ft_putnbr_fd(game->moves->player_move, 1);
		//ft_putendl_fd("", 1);
		mlx_string_put(mlx->mlx, mlx->win, 10, 5, 0xFFFF00, "Movements: ");
		nb = ft_itoa(mlx->moves);
		mlx_string_put(mlx->mlx, mlx->win, 140, 5, 0xFFFF00, nb);
		free(nb);
		nb = NULL;
	}
}

static void	iscollectable(t_game *game)
{
	int				k;

	k = 0;
	while (k < game->collcount)
	{
		if (game->moves->coll[k].x == game->moves->player.x
			&& game->moves->coll[k].y == game->moves->player.y)
		{
			game->moves->coll[k].x = -1;
			game->moves->coll[k].y = -1;
			game->moves->player_coll++;
		}
		k++;
	}
}

void	update(t_game *game)
{
	int				x;
	int				y;

	x = game->moves->player.x;
	y = game->moves->player.y;
	if (game->moves->player_up != 0)
		move_up(game, x, y);
	else if (game->moves->player_down != 0)
		move_down(game, x, y);
	else if (game->moves->player_left != 0)
		move_left(game, x, y);
	else if (game->moves->player_right != 0)
		move_right(game, x, y);
	had_move(game, x, y);
	iscollectable(game);
	adding_in_graphics(game);
	if (game->exit.x == game->moves->player.x
		&& game->exit.y == game->moves->player.y)
		if (game->moves->collcount == game->moves->player_coll)
			exit_point(game);
}
