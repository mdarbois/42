/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:27:46 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/12 12:27:52 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_lstadd_back(t_parser **lst, t_parser *new)
{
	t_parser	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
    new->prev = last;
}

t_parser	*ft_lstlast(t_parser *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_parser	*ft_lstnew(void *content)
{
	t_parser	*new;

	new = NULL;
	new = (t_parser *)malloc(sizeof(*new));
	if (new == NULL)
		return ((new));
	new->pipe_output = content;
    new->command = NULL;
    new->pipe_fd = 0;
    new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_token	*ft_lexernew(char *str, int token)
{
	t_token		*new_element;
	static int	i = 0;

	new_element = malloc(sizeof(t_token));
	if (!new_element)
		return (0);
	new_element->str = str;
	new_element->token = token;
	new_element->i = i++;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}
