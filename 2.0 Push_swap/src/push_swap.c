/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:09:33 by mdarbois          #+#    #+#             */
/*   Updated: 2023/02/13 14:09:35 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	initialize_stack(t_list **stack_a, t_list **stack_b, char **spl)
{
	int	i;
	int	t;

	i = 0;
	*stack_a = NULL;
	*stack_b = NULL;
	if (!spl)
		return (-1);
	while (spl[i])
		i++;
	while (--i >= 0)
	{
		t = add_to_list(stack_a, ft_long_atoi(spl[i]));
		if (t == -1)
			return (-1);
		free(spl[i]);
	}
	free(spl);
	return (1);
}

static int	split_len(char **spl)
{
	int	i;

	i = -1;
	if (!spl)
		return (-1);
	while (spl[++i])
		free(spl[i]);
	free(spl);
	return (i);
}

static char	**spliter(int argc, char **argv)
{
	int		i;
	char	**split;

	if (argc > 2)
	{
		i = 0;
		split = malloc(sizeof(char *) * argc);
		while (++i < argc)
		{
			if (split_len(ft_split(argv[i], ' ')) != 1 || !split)
			{
				i++;
				while (--i != 0 || split != NULL)
					free(split[i]);
				free(split);
				return (NULL);
			}
			split[i - 1] = ft_strdup(argv[i]);
		}
		split[argc - 1] = NULL;
		return (split);
	}
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	return (NULL);
}

static void	launch_algo(t_list *stack_a, t_list *stack_b, t_mq *mq)
{
	if (mq->len == 2)
		if (stack_a->data > stack_a->next->data)
			ft_printf("sa\n");
	if (mq->len > 2)
		if (!is_sorted(stack_a))
			push_b_optimize(stack_a, stack_b, mq);
	free_everything(&stack_a, &stack_b, &mq);
	exit(1);
}
// printf("len %d med %d q1 %d q2 %d\n", mq->len, mq->med, mq->q1, mq->q2);

int	main(int argc, char **argv)
{
	t_mq	*mq;
	int		error;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		exit(1);
	mq = malloc(sizeof(t_mq));
	if (!mq)
		return (0);
	error = 0;
	get_median_quartil(spliter(argc, argv), &mq, &error);
	if (error || mq->len == 0 || !mq)
	{
		ft_printf("Error\n");
		if (mq)
			free(mq);
		return (1);
	}
	if (initialize_stack(&stack_a, &stack_b, spliter(argc, argv)) == 1)
		launch_algo(stack_a, stack_b, mq);
	free_stack(&stack_a);
	free(mq);
	return (0);
}
