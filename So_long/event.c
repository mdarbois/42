
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
