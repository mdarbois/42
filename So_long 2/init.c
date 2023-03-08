#include "./include/so_long.h"

static void	texture_load(t_board *board, t_img **img, char *path)
{
	int				width;
	int				height;

	*img = mlx_xpm_file_to_image(board->mlx_ptr, path, &width, &height);
	if (*img == 0)
		destroy(0, "texture_init(): can't load texture", 0);
	(*img)->width = width;
	(*img)->height = height;
}

static void	texture_init(t_board *board)
{
	texture_load(board, &board->player, "./img/player.xpm");
	texture_load(board, &board->exit, "./img/helicopter.xpm");
	texture_load(board, &board->coll, "./img/gas.xpm");
	texture_load(board, &board->wall, "./img/wall.xpm");
	texture_load(board, &board->floor, "./img/sand.xpm");
}

static void	renderer_init(t_board *board)
{
	board->mlx_ptr = mlx_init();
	if (board->mlx_ptr == 0)
		destroy(board, "mlx_init(): can't load mlx", 0);
	board->win_ptr = mlx_new_window(board->mlx_ptr, board->game->width * 40,
			board->game->height * 40, "so_long");
	if (board->wi_ptrn == 0)
		destroy(board, "mlx_new_window(): can't create a window", 0);
	board->mlx_img = mlx_new_image(board->mlx_ptr, board->game->width * 40,
			board->game->height * 40);
	if (board->mlx_img == 0)
		destroy(board, "mlx_new_image(): can't create an image", 0);
}

t_board	*board_init(char *filename)
{
	t_board			*board;

	board = (t_board *)malloc(sizeof(t_board));
	if (board == 0)
		destroy(0, "board_init(): malloc()", errno);
	board->game = 0;
	board->mlx_ptr = 0;
	board->win_ptr = 0;
	board->mlx_img = 0;
	board->player = 0;
	board->exit = 0;
	board->coll = 0;
	board->wall = 0;
	board->floor = 0;
	game_init(board, filename);
	renderer_init(board);
	texture_init(board);
	return (board);
}
