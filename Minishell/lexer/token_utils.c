/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiffert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:13:28 by msiffert          #+#    #+#             */
/*   Updated: 2023/05/31 11:13:29 by msiffert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_lexeradd_back(t_token **lst, t_token *new)
{
	t_token	*tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

int	is_space(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

int	skip_spaces(char *str, int i)
{
	int	j;

	j = 0;
	while (is_space(str[i + j]))
		j++;
	return (j);
}

int	check_separator(int c)
{
	static int	token_arr[3][2] = {
	{'|', PIPE},
	{'>', INPUT},
	{'<', OUTPUT},
	};
	int			i;

	i = 0;
	while (i < 3)
	{
		if (token_arr[i][0] == c)
			return (token_arr[i][1]);
		i++;
	}
	return (0);
}

int	handle_quotes(int i, char *str, char quote)
{
	int j;

	j = 0;
	if (str[i + j] == quote)
	{
		j++;
		while (str[i + j] != quote && str[i + j])
			j++;
		j++;
	}
	return (j);
}
