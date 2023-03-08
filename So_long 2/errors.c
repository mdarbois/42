#include "./include/so_long.h"

void	map_height(t_board *board, char *file)
{
	int				i;
	int				j;

	board->game->height = 1;
	i = board->game->width + 1;
	while (file[i] != 0)
	{
		j = 0;
		while (file[i + j] != 0 && file[i + j] != '\n')
			j++;
		if (board->game->width != j)
		{
			free(file);
			destroy(board, "map format is invalid", 0);
		}
		i += board->game->width + 1;
		board->game->height++;
	}
}

void	map_width(t_board *board, char *file)
{
	board->game->width = 0;
	while (file[board->game->width] && file[board->game->width] != '\n')
		board->game->width++;
	if (board->game->width == 0 || file[board->game->width] == 0)
	{
		free(file);
		destroy(board, "map file is invalid", 0);
	}
}

static int	isborder(t_board *board, int i)
{
	if (i < board->game->width
		|| i > (board->game->width + 1) * (board->game->height - 1)
		|| i % (board->game->width + 1) == 0
		|| i % (board->game->width + 1) == board->game->width - 1)
		return (1);
	return (0);
}

static void	isvalid(t_board *board, char *file, int i)
{
	if (file[i] == 'P')
		board->game->count_player++;
	else if (file[i] == 'E')
		board->game->count_exit++;
	else if (file[i] == 'C')
		board->game->count_coll++;
	else if (file[i] == '1' || file[i] == '0')
		return ;
	else
	{
		free(file);
		destroy(board, "map content is invalid", 0);
	}
}

void	map_isvalid(t_board *board, char *file)
{
	int				i;

	i = -1;
	while (file[++i] != 0)
	{
		if (file[i] == '\n')
			continue ;
		if (isborder(board, i))
		{
			if (file[i] != '1')
			{
				free(file);
				destroy(board, "map isn't surrounded by walls", 0);
			}
		}
		else
			isvalid(board, file, i);
	}
	if (board->game->count_player != 1
		|| board->game->count_exit != 1
		|| board->game->count_coll < 1)
	{
		free(file);
		destroy(board, "map configuration is invalid", 0);
	}
}
