/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_lexer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:53:19 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/22 11:53:20 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

t_token	*lst_new_token(char *str, int type, int quotes)
{
	t_token	*new;

	new = malloc(sizeof(t_token) * 1);
	if (!(new))
		return (NULL);
	new->str = str;
	new->type = type;
	new->quotes = quotes;
	new->var = false;
	new->var = false;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	lst_add_back_token(t_token **alst, t_token *new_node)
{
	t_token	*start;

	start = *alst;
	if (start == NULL)
	{
		*alst = new_node;
		return ;
	}
	if (alst && *alst && new_node)
	{
		while (start->next != NULL)
			start = start->next;
		start->next = new_node;
		new_node->prev = start;
	}		
}

void	lst_delone_token(t_token *lst, void (*del)(void *))
{
	if (del && lst && lst->str)
	{	
		(*del)(lst->str);
		lst->str = NULL;
	}
	if (lst->prev)
		lst->prev->next = lst->next;
	if (lst->next)
		lst->next->prev = lst->prev;
	free_ptr(lst);
}

void	lst_clear_token(t_token **lst, void (*del)(void *))
{
	t_token	*tmp;

	tmp = NULL;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		lst_delone_token(*lst, del);
		*lst = tmp;
	}
}

t_parser	*lst_last_cmd(t_parser *parser)
{
	while (parser && parser->next != NULL)
		parser = parser->next;
	return (parser);
}
