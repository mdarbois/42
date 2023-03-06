/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:09:27 by mdarbois          #+#    #+#             */
/*   Updated: 2023/02/13 14:09:28 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	new_element(int nbr, t_list **elem)
{
	(*elem) = malloc(sizeof(t_list));
	if (!(*elem))
		return (-1);
	(*elem)->data = nbr;
	(*elem)->next = NULL;
	(*elem)->prev = NULL;
	return (1);
}

void	free_everything(t_list **stack_a, t_list **stack_b, t_mq **mq)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free(*mq);
}

int	add_to_list(t_list **stack, int nbr)
{
	t_list	*elem;

	if (new_element(nbr, &elem) == -1)
		return (-1);
	if ((*stack) == NULL)
	{
		(*stack) = elem;
		(*stack)->next = *stack;
		(*stack)->prev = *stack;
	}
	else
	{
		elem->prev = (*stack)->prev;
		elem->next = (*stack);
		(*stack)->prev->next = elem;
		(*stack)->prev = elem;
		(*stack) = elem;
	}
	return (1);
}

void	free_stack(t_list **stack)
{
	t_list	*current;
	t_list	*tmp;

	if ((*stack) == NULL)
		return ;
	current = (*stack);
	while (current->next != (*stack))
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(current);
	*stack = NULL;
}

int	len(t_list *stack)
{
	t_list	*tmp;
	int		i;

	if ((stack) && stack->next != stack)
	{
		tmp = (stack)->next;
		i = 1;
		while (tmp != (stack))
		{
			++i;
			tmp = tmp->next;
		}
		return (i);
	}
	return (0);
}
