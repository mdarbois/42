/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:10:03 by mdarbois          #+#    #+#             */
/*   Updated: 2023/02/13 14:10:04 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a(t_list **stack_a, int print)
{
	if (*stack_a && (*stack_a)->next != *stack_a)
	{
		*stack_a = (*stack_a)->next;
		if (print)
			write(1, "ra\n", 3);
	}
}

void	rotate_b(t_list **stack_b, int print)
{
	if (*stack_b && (*stack_b)->next != *stack_b)
	{
		*stack_b = (*stack_b)->next;
		if (print)
			write(1, "rb\n", 3);
	}
}

void	rotate_both(t_list **s_a, t_list **s_b)
{
	if (*s_a && (*s_a)->next != *s_a && *s_b && (*s_b)->next != *s_b)
	{
		rotate_a(s_a, 0);
		rotate_b(s_b, 0);
		write(1, "rr\n", 3);
	}
}
