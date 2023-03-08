
#include "./include/so_long.h"

static void	had_move(t_board *board, int x, int y)
{
	//if (board->game->player.x != x || board->game->player.y != y)
	//{
	//	board->game->player_move++;
	//	ft_putnbr_fd(board->game->player_move, 1);
	//	ft_putendl_fd("", 1);
	//}
	mlx_string_put(board->mlx_ptr, board->win_ptr, 10, 5, 0xFFFF00, "Movements: ");
	nb = ft_itoa(board->game->player_move);
	mlx_string_put(board->mlx_ptr, board->win_ptr, 140, 5, 0xFFFF00, nb);
	free(nb);
	nb = NULL;
}

static void	iscollectable(t_board *board)
{
	int				k;

	k = 0;
	while (k < board->game->count_coll)
	{
		if (board->game->coll[k].x == board->game->player.x
			&& board->game->coll[k].y == board->game->player.y)
		{
			board->game->coll[k].x = -1;
			board->game->coll[k].y = -1;
			board->game->player_coll++;
		}
		k++;
	}
}

void	update(t_board *board)
{
	int				x;
	int				y;

	x = board->game->player.x;
	y = board->game->player.y;
	if (board->game->player_up != 0)
		move_up(board, x, y);
	else if (board->game->player_down != 0)
		move_down(board, x, y);
	else if (board->game->player_left != 0)
		move_left(board, x, y);
	else if (board->game->player_right != 0)
		move_right(board, x, y);
	had_move(board, x, y);
	iscollectable(board);
	graphics(board);
	if (board->game->exit.x == board->game->player.x
		&& board->game->exit.y == board->game->player.y)
		if (board->game->count_coll == board->game->player_coll)
			destroy(board, 0, 0);
}
