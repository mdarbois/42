/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:09:29 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/02 12:09:30 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

size_t	ft_strlen_nospace(const char *s)
{
	size_t	l;

	l = 0;
	if (!s)
		return (0);
	while (s[l + 1] != '\0' && s[l] != ' ')
		l++;
	return (l);
}

int	check_identifier_factor(char *string)
{
	int		fd;
	char	*sub;

	fd = 0; 
	sub = ft_substr(string, ft_strlen_nospace(string) - 4, 5);
	if (ft_strncmp(sub, ".xpm", 4) != 0)
	{
		free(sub);
		printf("Invalid file type, use .xpm!\n");
		return (1);
	}
	free(sub);
	fd = open(string, O_RDONLY);
	if (fd < 0)
		return (1);
	return (0);
}


int	is_identifier(char *line, int j)
{
	if ((line[j] == 'N' && line[j + 1] == 'O')
		|| (line[j] == 'S' && line[j + 1] == 'O')
		|| (line[j] == 'W' && line[j + 1] == 'E')
		|| (line[j] == 'E' && line[j + 1] == 'A')
		|| (line[j] == 'F' || line[j] == 'C'))
		return (0);
	return (1);
}
