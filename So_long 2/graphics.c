
#include "./include/so_long.h"

static void	draw_square(t_board *board, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 40)
	{
		i = 0;
		while (i < 40)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(board->mlx_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

static void	draw_env(t_board *board, int i, int j)
{
	int				k;

	if (board->game->exit.x == i && board->game->exit.y == j)
		draw_square(board, board->exit, i * 40, j * 40);
	k = -1;
	while (++k < board->game->count_coll)
		if (board->game->coll[k].x == i && board->game->coll[k].y == j)
			draw_square(board, board->coll, i * 40, j * 40);
	if (board->game->player.x == i && board->game->player.y == j)
		draw_square(board, board->player, i * 40, j * 40);
}

static void	draw_map(t_board *board)
{
	int				i;
	int				j;

	j = 0;
	while (j < board->game->height)
	{
		i = 0;
		while (i < board->game->width)
		{
			if (board->game->map[j][i] == 1)
				draw_square(board, board->wall, i * 40, j * 40);
			else
				draw_square(board, board->ground, i * 40, j * 40);
			draw_env(board, i, j);
			i++;
		}
		j++;
	}
}

void	draw(t_board *board)
{
	draw_map(board);
	mlx_put_image_to_window(board->mlx_ptr, board->win_ptr,
		board->mlx_img, 0, 0);
}
