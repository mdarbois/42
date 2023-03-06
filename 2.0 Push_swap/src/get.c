/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:09:19 by mdarbois          #+#    #+#             */
/*   Updated: 2023/02/13 14:09:20 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_index(t_list *stack, int elem)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->data == elem)
			return (i);
		tmp = tmp->next;
		++i;
	}
	return (i);
}

int	get_min(t_list *stack)
{
	int		min;
	t_list	*tmp;

	tmp = stack->next;
	min = stack->data;
	while (tmp != stack && tmp != NULL)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp-> next;
	}
	return (min);
}

int	get_max(t_list *stack)
{
	int		max;
	t_list	*tmp;

	tmp = stack->next;
	max = stack->data;
	while (tmp != stack && tmp != NULL)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp-> next;
	}
	return (max);
}

int	get_pos_to_place(t_list *stack, int elem)
{
	int		min;
	int		i;
	int		l;
	t_list	*tmp;

	min = get_min(stack);
	if (elem > get_max(stack) || elem < min)
		return (get_index(stack, min));
	l = len(stack);
	i = -1;
	tmp = stack;
	while (++i < l)
	{
		if (tmp->prev->data < elem && elem < tmp->data)
			return (i);
		tmp = tmp->next;
	}
	return (0);
}
