/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:09:48 by mdarbois          #+#    #+#             */
/*   Updated: 2023/02/13 14:09:50 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b, t_mq **mq)
{
	t_list	*tmp;

	if (add_to_list(stack_a, (*stack_b)->data) == -1)
	{
		free_everything(stack_a, stack_b, mq);
		exit(1);
	}
	tmp = (*stack_b);
	(*stack_b)->prev->next = (*stack_b)->next;
	(*stack_b)->next->prev = (*stack_b)->prev;
	(*stack_b) = (*stack_b)->next;
	free(tmp);
	write(1, "pa\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b, t_mq **mq)
{
	t_list	*tmp;

	if (add_to_list(stack_b, (*stack_a)->data) == -1)
	{
		free_everything(stack_a, stack_b, mq);
		exit(1);
	}
	tmp = (*stack_a);
	(*stack_a)->prev->next = (*stack_a)->next;
	(*stack_a)->next->prev = (*stack_a)->prev;
	(*stack_a) = (*stack_a)->next;
	free(tmp);
	write(1, "pb\n", 3);
}
