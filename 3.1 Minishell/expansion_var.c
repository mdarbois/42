/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:46:19 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/21 15:46:20 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	var_exists(t_data *data, char *var)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(var);
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], var, len) == 0)
			return (0);
		i++;
	}
	return (1);
}

char	*get_new_token_string(char *oldstr, char *var_value,
		int newstr_size, int index)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * newstr_size);
	if (!new_str)
		return (NULL);
	while (oldstr[i])
	{
		if (oldstr[i] == '$' && i == index)
		{
			copy_var_value(new_str, var_value, &j);
			i = i + var_length(oldstr + index) + 1;
			if (oldstr[i] == '\0')
				break ;
		}
		new_str[j++] = oldstr[i++];
	}
	new_str[j] = '\0';
	return (new_str);
}

char	*recover_val(t_token *token, char *str, t_data *data)
{
	char	*value;
	char	*var;

	var = identify_var(str);
	if (var && var_exists(data, var) == 0)
	{
		if (token != NULL)
			token->var = true;
		value = search_env_var(data, var);
	}
	else if (var && var[0] == '?' && var[1] == '=')
		value = ft_itoa(g_exit_code);
	else
		value = NULL;
	free_ptr(var);
	return (value);
}

static int	replace_var(t_token **token_node, char *var_value, int index)
{
	if (var_value == NULL)
	{
		if (erase_var(token_node, (*token_node)->str, index) == 1)
		{
			free_ptr(var_value);
			return (1);
		}
	}
	else
	{
		if (erase_and_replace(token_node, (*token_node)->str, \
		var_value, index) == NULL)
		{
			free_ptr(var_value);
			return (1);
		}
	}
	free_ptr(var_value);
	return (0);
}

int	var_expander(t_data *data, t_token **token_lst)
{
	t_token	*temp;
	int		i;

	temp = *token_lst;
	while (temp)
	{
		if (temp->type == VAR)
		{
			i = 0;
			while (temp->str[i])
			{
				update_status(&temp, temp->str[i]);
				if (temp->str[i] == '$'
					&& is_sep(temp->str[i + 1]) == false
					&& is_between_quotes(temp->str, i) == false
					&& (temp->quotes == QUOTE_OK || temp->quotes == QUOTE_D))
					replace_var(&temp,
						recover_val(temp, temp->str + i, data), i);
				else
					i++;
			}
		}
		temp = temp->next;
	}
	return (0);
}
