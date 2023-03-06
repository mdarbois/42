/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:08:58 by mdarbois          #+#    #+#             */
/*   Updated: 2023/02/13 14:09:01 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	count_move(t_list *stack_a, t_list *stack_b, int elem)
{
	int	count;
	int	index;

	index = get_index(stack_b, elem);
	count = 1;
	if (index > 1 && index > (len(stack_b) / 2))
		count += len(stack_b) - index - 1;
	else if (index > 1 && index <= (len(stack_b) / 2))
		count += index - 1;
	index = get_pos_to_place(stack_a, elem);
	if (index > 1 && index > (len(stack_a) / 2))
		count += len(stack_a) - index - 1;
	else if (index > 1 && index <= (len(stack_a) / 2))
		count += index - 1;
	return (count);
}

int	get_best_move(t_list *stack_a, t_list *stack_b)
{
	int		best_move_elem;
	int		move_count;
	int		best_move_count;
	t_list	*tmp;

	best_move_elem = stack_b->data;
	best_move_count = count_move(stack_a, stack_b, best_move_elem);
	tmp = stack_b->next;
	while (tmp != stack_b && tmp != NULL)
	{
		move_count = count_move(stack_a, stack_b, tmp->data);
		if (move_count < best_move_count)
		{
			best_move_count = move_count;
			best_move_elem = tmp->data;
		}
		tmp = tmp->next;
	}
	return (best_move_elem);
}

int	is_sorted(t_list *stack)
{
	int	i;
	int	length;

	length = len(stack);
	if (length > 0)
	{
		i = 1;
		while (i++ < length)
		{
			if (stack->data > stack->next->data)
				return (0);
			stack = stack->next;
		}
		return (1);
	}
	return (0);
}

int	inner(t_list *stack, int q1, int q2)
{
	t_list	*tmp;
	int		length;
	int		i;

	length = len(stack);
	i = 0;
	tmp = stack;
	while (i < length)
	{
		if (q1 <= tmp->data && tmp->data <= q2)
			return (1);
		tmp = tmp->next;
		++i;
	}
	return (0);
}

void	replace_stack(t_list **stack)
{
	int		m;
	int		index;
	t_list	*stack_a;

	stack_a = *stack;
	m = get_min(stack_a);
	if (stack_a->data != m)
	{
		index = get_index(stack_a, m);
		if (index <= len(stack_a) / 2)
			while (stack_a->data != m)
				rotate_a(&stack_a, 1);
		else
			while (stack_a->data != m)
				reverse_rotate_a(&stack_a, 1);
	}
	(*stack) = stack_a;
}
