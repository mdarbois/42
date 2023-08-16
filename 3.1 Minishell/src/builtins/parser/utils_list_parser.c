/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:41:35 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/22 11:53:28 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static void	initialize_parser(t_parser **parser)
{
	(*parser)->command = NULL;
	(*parser)->pipe_out = false;
	(*parser)->pipe_fd = 0;
	(*parser)->argument = NULL;
	(*parser)->prev = NULL;
	(*parser)->next = NULL;
}

t_parser	*lst_new_cmd(bool value)
{
	t_parser	*new_node;

	new_node = (t_parser *)malloc(sizeof(t_parser));
	if (!new_node)
		return (NULL);
	ft_memset(new_node, 0, sizeof(t_parser));
	new_node->pipe_out = value;
	initialize_parser(&new_node);
	return (new_node);
}

void	lst_add_back_cmd(t_parser **alst, t_parser *new_node)
{
	t_parser	*start;

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

static void	lst_delone_cmd(t_parser *lst, void (*del)(void *))
{
	if (lst->command)
		(*del)(lst->command);
	if (lst->argument)
		free_str_tab(lst->argument);
	if (lst->pipe_fd)
		(*del)(lst->pipe_fd);
	if (lst->fds)
		free_io(lst->fds);
	(*del)(lst);
}

void	lst_clear_cmd(t_parser **lst, void (*del)(void *))
{
	t_parser	*temp;

	temp = NULL;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		lst_delone_cmd(*lst, del);
		*lst = temp;
	}
}
