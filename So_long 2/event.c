#include "./include/so_long.h"

int	key_press(int keycode, t_board *board)
{
	if (keycode == 65307)
		destroy(board, 0, 0);
	if (keycode == 119)
		board->game->player_up = 1;
	if (keycode == 115)
		board->game->player_down = 1;
	if (keycode == 97)
		board->game->player_left = 1;
	if (keycode == 100)
		board->game->player_right = 1;
	update(board);
	return (0);
}

int	key_release(int keycode, t_board *board)
{
	if (keycode == 119)
		board->game->player_up = 0;
	if (keycode == 115)
		board->game->player_down = 0;
	if (keycode == 97)
		board->game->player_left = 0;
	if (keycode == 100)
		board->game->player_right = 0;
	update(board);
	return (0);
}

int	destroy_hook(int keycode, t_board *board)
{
	(void)keycode;
	(void)board;
	destroy(0, 0, 0);
	return (0);
}
