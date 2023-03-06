/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:09:11 by mdarbois          #+#    #+#             */
/*   Updated: 2023/02/13 14:09:13 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_for_opti(t_list **stack_a, t_list **stack_b,
							int pos_a, int pos_b)
{
	int	i;
	int	length_a;
	int	length_b;

	i = 0;
	length_a = len(*stack_a);
	length_b = len(*stack_b);
	if ((pos_a <= (length_a / 2)) && (pos_b <= (length_b / 2)))
	{
		while (i <= (pos_a - 1) && i <= (pos_b - 1))
		{
			rotate_both(stack_a, stack_b);
			i++;
		}
	}
	if ((pos_a > (length_a / 2)) && (pos_b > (length_b / 2)))
	{
		while (i < (length_a - pos_a) && i < (length_b - pos_b))
		{
			reverse_rotate_both(stack_a, stack_b);
			i++;
		}
	}
	return (i);
}

static t_list	*rr_rra(t_list *stack_a, int pos_a, int i)
{
	if (pos_a <= (len(stack_a) / 2))
	{
		while (i <= pos_a - 1)
		{
			rotate_a(&stack_a, 1);
			++i;
		}
	}
	else
	{
		while (i < (len(stack_a) - pos_a))
		{
			reverse_rotate_a(&stack_a, 1);
			++i;
		}
	}
	return (stack_a);
}

void	insertion_sort(t_list **s_a, t_list **s_b, int best_move, t_mq **mq)
{
	int	pos_a;
	int	pos_b;
	int	i;

	pos_a = get_pos_to_place((*s_a), best_move);
	pos_b = get_index((*s_b), best_move);
	i = check_for_opti(s_a, s_b, pos_a, pos_b);
	while ((*s_b)->data != best_move)
	{
		if (pos_b <= (len((*s_b)) / 2))
			rotate_b(s_b, 1);
		else
			reverse_rotate_b(s_b, 1);
	}
	(*s_a) = rr_rra((*s_a), pos_a, i);
	push_a(s_a, s_b, mq);
}

void	push_b_optimize(t_list *stack_a, t_list *stack_b, t_mq *mq)
{
	while (inner(stack_a, mq->q1, mq->q2) && mq->len >= 8)
	{
		if (stack_a->data >= mq->q1 && stack_a->data <= mq->med)
		{
			push_b(&stack_a, &stack_b, &mq);
			rotate_b(&stack_b, 1);
			continue ;
		}
		if (stack_a->data <= mq->q2 && stack_a->data >= mq->med)
		{
			push_b(&stack_a, &stack_b, &mq);
			continue ;
		}
		else
			rotate_a(&stack_a, 1);
	}
	while (len(stack_a) > 3)
	{
		push_b(&stack_a, &stack_b, &mq);
		if (stack_b->data < mq->med)
			rotate_b(&stack_b, 1);
	}
	if (!(is_sorted(stack_a)))
		sort_three(&stack_a);
	push_a_optimize(stack_a, stack_b, mq);
}

void	push_a_optimize(t_list *stack_a, t_list *stack_b, t_mq *mq)
{
	mq->len -= 3;
	while (mq->len)
	{
		insertion_sort(&stack_a, &stack_b,
			get_best_move(stack_a, stack_b), &mq);
		mq->len--;
	}
	replace_stack(&stack_a);
	stack_b = NULL;
	free_everything(&stack_a, &stack_b, &mq);
	exit(1);
}
