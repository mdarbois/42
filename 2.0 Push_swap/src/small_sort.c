/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:10:19 by mdarbois          #+#    #+#             */
/*   Updated: 2023/02/13 14:10:20 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	fill_mq(t_mq **mq, int len, int array[])
{
	if (len % 2 == 0)
		(*mq)->med = len / 2;
	(*mq)->q1 = (((*mq)->med) + 1) / 2;
	if ((*mq)->med % 2 == 0)
		(*mq)->q1 = ((*mq)->med) / 2;
	(*mq)->q2 = ((*mq)->med) + ((*mq)->q1);
	if (len > 5)
	{
		(*mq)->q1 = array[(*mq)->q1];
		(*mq)->q2 = array[(*mq)->q2];
	}
	else
	{
		(*mq)->q1 = 0;
		(*mq)->q2 = 0;
	}
}

void	sort_three(t_list **stack_a)
{
	int	fst;
	int	scd;
	int	trd;

	fst = (*stack_a)->data;
	scd = (*stack_a)->next->data;
	trd = (*stack_a)->prev->data;
	if ((fst < scd) && (scd > trd) && (fst < trd))
	{
		reverse_rotate_a(stack_a, 1);
		swap_a(stack_a, 1);
	}
	else if ((fst < scd) && (scd > trd) && (fst > trd))
		reverse_rotate_a(stack_a, 1);
	else if ((fst > scd) && (scd < trd) && (fst > trd))
		rotate_a(stack_a, 1);
	else if ((fst > scd) && (scd > trd))
	{
		swap_a(stack_a, 1);
		reverse_rotate_a(stack_a, 1);
	}
	else
		swap_a(stack_a, 1);
}
