#include "./include/so_long.h"

static void	free_matrix(t_board *board, char *file, int **m, int size)
{
	int				i;

	i = 0;
	while (i < size)
		free(m[i++]);
	free(m);
	board->game->map = 0;
	free(file);
	destroy(board, "map_parsing(): malloc()", errno);
}

static void	get_coord(t_board *board, char *file, int k, int *obj)
{
	if (file[k] == 'P')
	{
		board->game->player.x = k % (board->game->width + 1);
		board->game->player.y = k / (board->game->width + 1);
		file[k] = '0';
	}
	else if (file[k] == 'E')
	{
		board->game->exit.x = k % (board->game->width + 1);
		board->game->exit.y = k / (board->game->width + 1);
		file[k] = '0';
	}
	else if (file[k] == 'C')
	{
		board->game->coll[*obj].x = k % (board->game->width + 1);
		board->game->coll[*obj].y = k / (board->game->width + 1);
		file[k] = '0';
		(*obj)++;
	}
}

void	map_parsing(t_board *board, char *file)
{
	int				i;
	int				j;
	int				k;
	int				obj;

	obj = 0;
	k = 0;
	j = -1;
	while (++j < board->game->height)
	{
		board->game->map[j] = (int *)malloc(sizeof(int) * board->game->width);
		if (board->game->map[j] == 0)
			free_matrix(board, file, board->game->map, j);
		i = 0;
		while (i < board->game->width)
		{
			get_coord(board, file, k, &obj);
			board->game->map[j][i++] = file[k++] - 48;
		}
		k++;
	}
}
