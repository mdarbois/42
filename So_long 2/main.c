#include "./include/so_long.h"

int	main(int argc, char **argv)
{
	t_board			*board;

	if (argc != 2)
	{
		ft_printf("Invalid number of arguments!");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(ft_substr(argv[1],ft_strlen(argv[1]) - 4, 5),
			".ber", 5) != 0)
	{
		ft_printf("Invalid file type, user .ber!");
		exit(EXIT_FAILURE);
	}
	board = board_init(av[1]);
	graphics(board);
	mlx_hook(board->win_ptr, 2, 1L << 0, key_press, board);
	mlx_hook(board->win_ptr, 3, 1L << 1, key_release, board);
	mlx_hook(board->win_ptr, 17, 1L << 17, destroy_hook, board);
	mlx_loop(board->mlx_ptr);
	return (0);
}
