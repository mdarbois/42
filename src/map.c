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

/* char *extract_color(char *string)
{
	int i;
	i = 0;
	char *color;
	color = (char *)malloc(sizeof(char) * ft_strlen(string));
	while (string[i] != '\n' && string[i] == ' ')
		i++;

} */

char *extract_path(char *string)
{
	int i;
	int j;
	i = 0;
	j = 0;
	char *path;
	
	path = (char *)malloc(sizeof(char) * ft_strlen(string));
	while (string[i] != '\n' && string[i] == ' ')
		i++;
	while (string[i] != '\n')
	{
		if (string[i] == ' ')
			i++;
		path[j] = string[i];
		i++;
		j++;
	}
	path[j] = '\0';
	return(path);
}

int identifier(t_board *board, char *line)
{
	int j;

	j = 0;

	if (!line || line[j] == '\n')
		return (0);

	while (line[j] != '\n' && line[j] != '1' && line[j+1] != '1' && line[j+2] != '1')
	{
		if (line[j] == 'N' && line[j+1] == 'O')
		{
			if (line[j+2] == '\n')
				printf("Error: you must first specify the type identifier and then the informations\n");
			board->no = extract_path(ft_substr(line, j+2, ft_strlen(line)));
			return (0);
		}
		else if (line[j] == 'S' && line[j+1] == 'O')
		{
			if (line[j+2] == '\n')
				printf("Error: you must first specify the type identifier and then the informations\n");
			board->so = extract_path(ft_substr(line, j+2, ft_strlen(line)));
			return (0);
		}
		else if (line[j] == 'W' && line[j+1] == 'E')
		{
			if (line[j+2] == '\n')
				printf("Error: you must first specify the type identifier and then the informations\n");
			board->we = extract_path(ft_substr(line, j+2, ft_strlen(line)));
			return (0);
		}
		else if (line[j] == 'E' && line[j+1] == 'A')
		{
			if (line[j+2] == '\n')
				printf("Error: you must first specify the type identifier and then the informations\n");
			board->ea = extract_path(ft_substr(line, j+2, ft_strlen(line)));
			return (0);
		}
		else if (line[j] == 'F')
		{
			if (line[j+2] == '\n')
				printf("Error: you must first specify the type identifier and then the informations\n");
/* 			board->f = extract_color(ft_substr(line, j+1, ft_strlen(line)));
 */			return (0);
		}
		else if (line[j] == 'C')
		{
			if (line[j+2] == '\n')
				printf("Error: you must first specify the type identifier and then the informations\n");
		/* 	board->c = (char *)malloc(sizeof(char) * ft_strlen(line));
			board->c = line; */
			return (0);
		}
		j++;
	}
	return (0);
}


static int	add_line(t_board *board, char *line)
{
	char	**temporary;
	int		i;
	int     width;

	width = 0;
	i = 0;
	if (!line)
		return (0);
	board->height++;
	temporary = (char **)malloc(sizeof(char *) * (board->height + 1));
	if (!temporary)
		die( "init: malloc", 0);
	temporary[board->height] = NULL;

	while (i < board->height - 1)
	{
		temporary[i] = board->map[i];
		i++;
	}
	temporary[i] = line;
	width = ft_strlen(line) - 1;
	if (board->width < width)
		board->width = width;
	if (board->map)
		free(board->map);
	board->map = temporary;
	return (1);
}


int map_reading(t_board *board, char **argv)
{
	char *readline;
	board->fd = open(argv[1], O_RDONLY);
	if (board->fd < 0)
		return (0);
	while (1)
	{
		readline = get_next_line(board->fd);
		identifier(board, readline);
		if (!add_line(board, readline))
			break ;
	}
	close (board->fd);
	return (1);
}

/* #texture and color
#go through the file and look for the first character of each line until reached 1
# starts with NO, SO, WE, EA
	#between type identifier and info multiple spaces are allowed
	#check if path is correct
# starts with F  or C 
	#between type identifier and info multiple spaces are allowed
	#3 numbers between 0 and 255 separated by commas

#map
# has to be at the end of the file
#only characters accepted: 1, 0, N, S, E, W
#map must be surrounded by walls "1"
#spaces will be turned to 0.

#otherwise "Error\n" followed by an explicit error message */