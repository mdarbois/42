/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:32:22 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/21 15:32:23 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

char	*heredoc_name(void)
{
	static int	i;
	char		*name;
	char		*character;

	character = ft_itoa(i);
	if (!character)
		return (NULL);
	name = ft_strjoin(ft_strdup("/tmp/.minishell_heredoc_"), character);
	free(character);
	i++;
	return (name);
}

char	*heredoc_delim(char *delim, bool *quotes)
{
	int	len;

	len = ft_strlen(delim) - 1;
	if ((delim[0] == '\"' && delim[len] == '\"')
		|| (delim[0] == '\'' && delim[len] == '\''))
	{
		*quotes = true;
		return (ft_strtrim(delim, "\'\""));
	}
	return (ft_strdup(delim));
}

static char	*expand_line(t_data *data, char *line)
{
	char	**words;
	int		i;

	words = ft_split(line, ' ');
	if (!words)
		return (NULL);
	i = 0;
	while (words[i])
	{
		if (ft_strchr(words[i], '$'))
		{
			words[i] = expander_heredoc(data, words[i]);
			if (!words[i])
				return (NULL);
		}
		i++;
	}
	return (make_str_from_tab(words));
}

static bool	heredoc_line(t_data *data, char **line,
									t_fds *io, bool *ret)
{
	if (*line == NULL)
	{
		ft_putstr_fd("warning:here-document delimited by end-of-file: wanted",
			STDERR_FILENO);
		*ret = true;
		return (false);
	}
	if (ft_strncmp(*line, io->heredoc_end, ft_strlen(io->heredoc_end)) == 0
		&& ft_strncmp(*line, io->heredoc_end, ft_strlen(*line)) == 0)
	{
		*ret = true;
		return (false);
	}
	if (io->heredoc_quotes == false && ft_strchr(*line, '$'))
	{
		*line = expand_line(data, *line);
		if (!(*line))
		{
			free_ptr(*line);
			*ret = false;
			return (false);
		}
	}
	return (true);
}

bool	heredoc_fill(t_data *data, t_fds *io, int fd)
{
	char	*line;
	bool	ret;

	ret = false;
	line = NULL;
	while (1)
	{
		signal_setup_sigint();
		line = readline("heredoc>");
		signal_setup_both();
		if (!heredoc_line(data, &line, io, &ret))
			break ;
		ft_putendl_fd(line, fd);
		free_ptr(line);
	}
	free_ptr(line);
	return (ret);
}
