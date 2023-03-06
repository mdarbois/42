
#include "./include/so_long.h"

static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_game *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->height_map++;
	temporary = (char **)malloc(sizeof(char *) * (game->height_map + 1));
	temporary[game->height_map] = NULL;
	while (i < game->height_map - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	temporary[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	return (1);
}

int	map_reading(t_game *game, char **argv)
{
	char	*readmap;
	int fd;

	fd = open(argv[1], O_RDONLY);
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
	close (fd);
	game->width_map = width_of_map(game->map[0]);
	
	return (1);
}