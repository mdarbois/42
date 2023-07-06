/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:40:02 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/21 17:02:38 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

char	*identify_var(char *str)
{
	char	*var;
	char	*tmp;
	int		start;
	int		len;
	int		i;

	i = 0;
	start = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			start = i + 1;
			break ;
		}
		i++;
	}
	len = var_length(str);
	var = ft_substr(str, start, len);
	if (!var)
		return (NULL);
	tmp = ft_strjoin(ft_strdup(var), "=");
	free_ptr(var);
	var = tmp;
	return (var);
}

static char	*replace_str_heredoc(char *str, char *var_value, int index)
{
	char	*tmp;

	tmp = NULL;
	if (var_value == NULL)
		*str = '\0';
	else
	{
		tmp = str;
		str = erase_and_replace(NULL, str, var_value, index);
		free_ptr(tmp);
	}
	free_ptr(var_value);
	return (str);
}

char	*expander_heredoc(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$'
			&& is_sep(str[i + 1]) == false
			&& is_between_quotes(str, i) == false)
			str = replace_str_heredoc(str, recover_val(NULL, str + i, data), i);
		else
			i++;
	}
	return (str);
}

char	*erase_and_replace(t_token **token_node, char *str,
			char *var_value, int index)
{
	char	*newstr;
	int		newstr_size;

	newstr_size = (ft_strlen(str) - var_length(str + index)
			+ ft_strlen(var_value));
	newstr = get_new_token_string(str, var_value, newstr_size, index);
	if (token_node && *token_node)
	{
		free_ptr((*token_node)->str);
		(*token_node)->str = newstr;
	}
	return (newstr);
}
