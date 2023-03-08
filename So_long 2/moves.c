#include "./include/so_long.h"

void	move_up(t_board *board, int x, int y)
{
	if (board->game->map[y - 1][x] == 0)
		board->game->player.y -= 1;
}

void	move_down(t_board *board, int x, int y)
{
	if (board->game->map[y + 1][x] == 0)
		board->game->player.y += 1;
}

void	move_left(t_board *board, int x, int y)
{
	if (board->game->map[y][x - 1] == 0)
		board->game->player.x -= 1;
}

void	move_right(t_board *board, int x, int y)
{
	if (board->game->map[y][x + 1] == 0)
		board->game->player.x += 1;
}
