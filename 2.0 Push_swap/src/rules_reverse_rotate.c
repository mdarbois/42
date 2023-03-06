/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:09:55 by mdarbois          #+#    #+#             */
/*   Updated: 2023/02/13 14:09:56 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate_a(t_list **stack_a, int print)
{
	if (*stack_a && (*stack_a)->prev != *stack_a)
	{
		*stack_a = (*stack_a)->prev;
		if (print)
			write(1, "rra\n", 4);
	}
}

void	reverse_rotate_b(t_list **stack_b, int print)
{
	if (*stack_b && (*stack_b)->prev != *stack_b)
	{
		*stack_b = (*stack_b)->prev;
		if (print)
			write(1, "rrb\n", 4);
	}
}

void	reverse_rotate_both(t_list **s_a, t_list **s_b)
{
	if (*s_a && (*s_a)->prev != *s_a && *s_b && (*s_b)->prev != *s_b)
	{
		reverse_rotate_a(s_a, 0);
		reverse_rotate_b(s_b, 0);
		write(1, "rrr\n", 4);
	}
}
