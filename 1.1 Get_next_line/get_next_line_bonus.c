/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:13:14 by mdarbois          #+#    #+#             */
/*   Updated: 2023/01/05 12:13:24 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *line)
{
	char	*buf;
	int		octets;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	octets = 1;
	while (!ft_strchr(line, '\n') && octets != 0)
	{
		octets = read(fd, buf, BUFFER_SIZE);
		if (octets == -1)
		{
			free(buf);
			if (line)
				free(line);
			return (NULL);
		}
		buf[octets] = '\0';
		line = ft_strjoin(line, buf);
	}
	free (buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[4096];
	char		*str;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = ft_read(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	str = ft_copy_line(line[fd]);
	line[fd] = ft_new_str(line[fd]);
	return (str);
}
