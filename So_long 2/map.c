#include "./include/so_long.h"

void	map_read(t_board *board, char *file)
{
	map_width(board, file);
	map_height(board, file);
	map_isvalid(board, file);
	board->game->coll
		= (t_coord *)malloc(sizeof(t_coord) * board->game->count_coll);
	if (board->game->coll == 0)
	{
		free(file);
		destroy(board, "map_parsing(): malloc()", errno);
	}
	board->game->map = (int **)malloc(sizeof(int *) * board->game->height);
	if (board->game->map == 0)
	{
		free(file);
		destroy(board, "map_parsing(): malloc()", errno);
	}
	map_parsing(board, file);
}

void	map_init(t_board *board, char *filename)
{
	int				fd;
	char			*file;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("File not found!");
		exit(EXIT_FAILURE);
		return (0);
	}
	while (1)
	{
		readmap = get_next_line(fd);
		if (!add_line(game, readmap))
			break ;
	}
	close(fd);
	map_read(board, file);
	//free(file);
}

void	game_init(t_board *board, char *filename)
{
	board->game = (t_game *)malloc(sizeof(t_game));
	if (board->game == 0)
		destroy(board, "game_init(): malloc()", errno);
	board->game->map = 0;
	board->game->coll = 0;
	board->game->count_coll = 0;
	board->game->count_exit = 0;
	board->game->count_player = 0;
	board->game->player_move = 0;
	board->game->player_coll = 0;
	board->game->player_up = 0;
	board->game->player_down = 0;
	board->game->player_left = 0;
	board->game->player_right = 0;
	map_init(board, filename);
}
