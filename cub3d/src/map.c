/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:30:40 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/02 10:30:42 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	extract_path(t_board *board, char *line, int i, int type)
{
	int		j;
	char	*sub;

	j = ft_strlen(line) - 1;
	i += 2;
	while (line[i] == ' ')
		i++;
	while (line[j] == ' ')
		j--;
	if (j < i)
		return (ft_error(board, "Invalid element info\n", 1));
	sub = ft_substr(line, i, j - i + 1);
	if (type == 1)
		board->no = ft_strdup(sub);
	else if (type == 2)
		board->so = ft_strdup(sub);
	else if (type == 3)
		board->we = ft_strdup(sub);
	else if (type == 4)
		board->ea = ft_strdup(sub);
	free(sub);
	return (EXIT_SUCCESS);
}

static int	identifier(t_board *board, char *line)
{
	int	j;

	j = 0;
	while (line[j] == ' ')
		j++;
	if (line[j] == 'N' && line[j + 1] == 'O')
	{
		if (board->no == NULL)
			return (extract_path(board, line, j, 1));
		else
			return (ft_error(board, "Double elements (NO)\n", 1));
	}
	else if (line[j] == 'S' && line[j + 1] == 'O')
	{
		if (board->so == NULL)
			return (extract_path(board, line, j, 2));
		else
			return (ft_error(board, "Double elements (SO)\n", 1));
	}
	else if (line[j] == 'W' && line[j + 1] == 'E')
	{
		if (board->we == NULL)
			return (extract_path(board, line, j, 3));
		else
			return (ft_error(board, "Double elements (WE)\n", 1));
	}
	else if (line[j] == 'E' && line[j + 1] == 'A')
	{
		if (board->ea == NULL)
			return (extract_path(board, line, j, 4));
		else
			return (ft_error(board, "Double elements (EA)\n", 1));
	}
	return (EXIT_FAILURE);
}



/* static int	add_line(t_board *board, char *line)
{
	char	**temporary;
	int		i;
	int		width;

	width = 0;
	i = 0;
	printf("line=%s\n", line);
	if (!line)
		return (0);
	board->height++;
	temporary = (char **)malloc(sizeof(char *) * (board->height + 1));
	if (!temporary)
		die("init: malloc", 0);
	temporary[board->height] = NULL;
	while (i++ < board->height - 1)
		temporary[i] = board->map[i];
	temporary[i] = line;
	width = ft_strlen(line) - 1;
	if (board->width < width)
		board->width = width;
	if (board->map)
		free(board->map);
	board->map = temporary;
	return (1);
} */

/* static char	**get_input_file(t_board *board, char *line)
{
	char	*final_line;
	char	**input;
	char	*temp;

	temp = NULL;
	final_line = ft_strdup("");
	temp = ft_strjoin(final_line, line);
	free(final_line);
	final_line = ft_strdup(temp);
	free_two_strings(temp, line);


	if (ft_strncmp(line, "\n", 1) == 0)
	{
		free(final_line);
		return (1);
	}
	board->map = ft_split(final_line, '\n');
	free(final_line);
	return (0);
} */

/* int	identifier(t_board *board, char *line)
{
	int	j;

	j = 0;
	if (!line)
		return (0);
	while (line[j] != '\n' && line[j] != '1'
		&& line[j + 1] != '1' && line[j + 2] != '1')
	{ 
		if (!is_identifier(line, j))
		{
			if (line[j + 2] == '\n')
				printf("Error: first type identifier and then info\n");
			else if (line[j] == 'F' || line[j] == 'C')
				extract_color(line, j, board);
			else
				extract_path(line, j, board);
			return (1);
		}
		j++;
	}
	return (0);
} */

static int	get_elements(t_board *board, char **map)
{
	int	i;

	i = 0;
	while (map[i] != 0)
	{
		if (!ft_strncmp(map[i], "\n", ft_strlen(map[i])))
			i++;
		else if (!identifier(board, map[i]))
			i++;
		else if (!extract_color(board, map[i]))
			i++;
		else
			break ;
	}
	return (i);
}

char **map_reading(t_board *board, int fd)
{
	char	*readline;
	char	*final;

	
/* 	readline = get_next_line(fd);
	while (readline != NULL)
	{
		if (!identifier(board, readline) && (board->no && board->so && board->ea && board->we && board->c && board->f))
		{
			
			if (ft_strncmp(readline, "\n", 1) == 0 )
				printf("error");
			printf("readline=%s", readline);
			if (!add_line(board, readline))
			{
				ft_error(board,"New lines in map\n", 1);
				return (0);
			} 
		}
		readline = get_next_line(board->fd);
	}
	
	return (1); */
	char	**map;
	char	*temp;

	temp = NULL;
	final = ft_strdup("");
	readline = get_next_line(fd);
	while (readline != NULL)
	{
		temp = ft_strjoin(final, readline);
		free(final);
		final = ft_strdup(temp);
		/* free_two_strings(temp, readline); */
		readline = get_next_line(fd);
	}
	free(readline);
	/* if (check_extra_lines(final) == 0)
	{
		free(final);
		ft_error(board, "New lines in map\n", 1);
	} */
	map = ft_split(final, '\n');
	free(final);
	close (board->fd);
	return (map);
}


int check_input(t_board *board, char **argv)
{
	int index;

	index = get_elements(board, board->map);
	if (!board->no || !board->so
		|| !board->we || !board->ea)
		return (ft_error(board, "Texture file(s) missing\n", 1));
	board->fd = open(argv[1], O_RDONLY);
	if (board->fd < 0)
		die("Error opening the file\n", 0);
	board->map = map_reading(board, board->fd);
	if (!board->map)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}

/* if (line[j] == 'N' && line[j + 1] == 'O')
		{
			if (line[j + 2] == '\n')
				die("Error: you must first specify the type identifier and then the informations\n", 0);
			board->no = ft_strtrim(ft_substr(line, j + 2, ft_strlen(line)), " ");
			return (1); 
		}
		else if (line[j] == 'S' && line[j + 1] == 'O')
		{
			if (line[j + 2] == '\n')
				die("Error: you must first specify the type identifier and then the informations\n", 0);
			board->so = ft_strtrim(ft_substr(line, j + 2, ft_strlen(line)), " ");
			return (1);
		}
		else if (line[j] == 'W' && line[j + 1] == 'E')
		{
			if (line[j + 2] == '\n')
				die("Error: you must first specify the type identifier and then the informations\n", 0);
			board->we = ft_strtrim(ft_substr(line, j + 2, ft_strlen(line)), " ");
			return (1);
		}
		else if (line[j] == 'E' && line[j + 1] == 'A')
		{
			if (line[j + 2] == '\n')
				die("Error: you must first specify the type identifier and then the informations\n", 0);
			board->ea = ft_strtrim(ft_substr(line, j + 2, ft_strlen(line)), " ");
			return (1);
		} */


		/* 
char	*extract_path(char *string)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	j = 0;
	path = (char *)malloc(sizeof(char) * ft_strlen(string));
	while (string[i] != '\n' && string[i] == ' ')
		i++;
	while (string[i] != '\n')
	{
		path[j] = string[i];
		i++;
		j++;
	}
	path[j] = '\0';
	return (path);
} */