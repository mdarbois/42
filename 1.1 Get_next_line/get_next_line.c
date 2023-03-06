/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:12:29 by mdarbois          #+#    #+#             */
/*   Updated: 2023/01/05 12:12:37 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char		*str;
	static char	*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read(fd, line);
	if (!line)
		return (NULL);
	str = ft_copy_line(line);
	line = ft_new_str(line);
	return (str);
}

// undefined behavior if the file pointed to by the fd changed 
//since the last call whereas read() didn’t reach the end of file.
//undefined behavior when reading a binary file. 

//returned line should include the terminating \n character, 
//except if the end of file was reached and does not end with a \n character.

/* COMPILER
compiler call: -D BUFFER_SIZE=n
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
It will define the buffer size for read().
The buffer size value will be modified by your peer-evaluators 
and the Moulinette in order to test your code.
*/

/* RETURN VALUE
Read line:  correct behavior
NULL: there is nothing else to read, or an error occurred
Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return NULL.
*/
