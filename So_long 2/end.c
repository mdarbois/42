#include "./include/so_long.h"

void	game_destroy(t_game *game)
{
	int				i;

	if (game != 0)
	{
		if (game->coll != 0)
			free(game->coll);
		if (game->map != 0)
		{
			i = 0;
			while (i < game->height)
				free(game->map[i++]);
			free(game->map);
		}
		free(game);
	}
}

void	die(char *errmsg, int errnum)
{
	if (errmsg != 0 || errnum != 0)
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

void	destroy(t_board *board, char *errmsg, int errnum)
{
	if (board != 0)
	{
		if (board->ground != 0)
			mlx_destroy_image(board->mlx_ptr, board->floor);
		if (board->wall != 0)
			mlx_destroy_image(board->mlx_ptr, board->wall);
		if (board->coll != 0)
			mlx_destroy_image(board->mlx_ptr, board->coll);
		if (board->exit != 0)
			mlx_destroy_image(board->mlx_ptr, board->exit);
		if (board->player != 0)
			mlx_destroy_image(board->mlx_ptr, board->player);
		if (board->mlx_img != 0)
			mlx_destroy_image(board->mlx_ptr, board->mlx_img);
		if (board->win_ptr != 0)
			mlx_destroy_window(board->mlx_ptr, board->mlx_win);
		if (board->mlx_ptr != 0)
			mlx_destroy_display(board->mlx_ptr);
		if (board->game != 0)
			game_destroy(board->game);
		free(board);
	}
	die(errmsg, errnum);
}
