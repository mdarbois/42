/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:06:38 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/06 15:06:40 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int get_color_ceiling(t_board *board, char **split)
{
    board->c = (int *)malloc(sizeof(int) * 3);
    board->c[0] = ft_atoi(split[0]);
	board->c[1] = ft_atoi(split[1]);
	board->c[2] = ft_atoi(split[2]);
	free_array(split);
    if (board->c[0] < 0 || board->c[0] > 255)
		return (ft_error(board, "Color input is invalid\n", 1));
	else if (board->c[1] < 0 || board->c[1] > 255)
		return (ft_error(board, "Color input is invalid\n", 1));
	else if (board->c[2] < 0 || board->c[2] > 255)
		return (ft_error(board, "Color input is invalid\n", 1));
	return (EXIT_SUCCESS);
}

static int get_color_floor(t_board *board, char **split)
{
    board->f = (int *)malloc(sizeof(int) * 3);
    board->f[0] = ft_atoi(split[0]);
	board->f[1] = ft_atoi(split[1]);
	board->f[2] = ft_atoi(split[2]);
	free_array(split);
    if (board->f[0] < 0 || board->f[0] > 255)
		return (ft_error(board, "Color input is invalid\n", 1));
	else if (board->f[1] < 0 || board->f[1] > 255)
		return (ft_error(board, "Color input is invalid\n", 1));
	else if (board->f[2] < 0 || board->f[2] > 255)
		return (ft_error(board, "Color input is invalid\n", 1));
	return (EXIT_SUCCESS);
}


int get_colors(t_board *board, char **split, int type)
{
	int	i;

	i = 0;
	while (split[i] != 0)
		i++;
	if (i != 3)
		return (EXIT_FAILURE);
	if (type == 1)
        return (get_color_floor(board, split));
	else if (type == 2)
		return (get_color_ceiling(board, split));
	return (EXIT_SUCCESS);
}

static int	check_color_comma(t_board *board, char *string, int i)
{
	int		comma;

	comma = 0;
	if (string[i] == ',')
		return (ft_error(board, "Color input is invalid beg comma\n", 1));
	while (string[i] != '\0')
	{
		if (string[i] == ',' && string[i + 1] == ',')
			return (ft_error(board, "Color is invalid comma in a row\n", 1));
		else if (string[i] == ',' && string[i + 1] != ',')
			comma++;
		i++;
	}
	if (string[i] == ',')
		return (ft_error(board, "Color input is invalid last comma\n", 1));
	if (comma != 2)
		return (ft_error(board, "Color input is invalid\n", 1));
	return (EXIT_SUCCESS);
}

int check_color(t_board *board, char *string, int i, int type)
{
	char	**split;
	char	*color;
    int j;
/* 	color = (char *)malloc(sizeof (char) * 12);
	split = (char **)malloc(sizeof (char *) * ft_strlen(string));
	split = ft_split(string, ',');
	if (split[3] || !check_range(split[0]) || !check_range(split[1]) || !check_range(split[2]))
	{
		free(color);
		free_array(split);
		die("Error, 3 digits expected between 0 and 255", 0);
	}
	color = ft_strjoin(ft_strtrim(split[0], " "), ",");
	color = ft_strjoin(color, ft_strtrim(split[1], " "));
	color = ft_strjoin(color, ",");
	color = ft_strjoin(color, ft_strtrim(split[2], " "));
	free_array(split);
	return (color); */

	j = ft_strlen(string) - 1;
	i++;
	while (string[i] != '\0' && string[i] == ' ')
		i++;
	while (string[j] == ' ')
		j--;
	if (check_color_comma(board, string, i))
		return (EXIT_FAILURE);
	color = ft_substr(string, i, j - i + 1);
	split = ft_split(color, ',');
	free(color);
	if (get_colors(board, split, type))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	extract_color(t_board *board, char *line)
{
	int i;
	i = 0;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (line[i] == 'F')
		return (check_color(board, line, i, 1));
	else if (line[i] == 'C')
		return (check_color(board, line, i, 2));
	return (EXIT_FAILURE);
}