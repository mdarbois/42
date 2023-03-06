/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:12:03 by mdarbois          #+#    #+#             */
/*   Updated: 2023/02/13 14:12:04 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/include/libft.h"

typedef struct s_list
{
	int				data;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct s_mq
{
	int	med;
	int	q1;
	int	q2;
	int	len;
}		t_mq;

int			get_best_move(t_list *pstack_a, t_list *stack_b);
int			is_sorted(t_list *stack);
int			inner(t_list *stack, int q1, int q2);
void		replace_stack(t_list **stack);

long long	ft_long_atoi(const char *str);
int			ft_atoi_and_check(const char *nptr, int *error);

void		insertion_sort(t_list **s_a, t_list **s_b,
				int best_move, t_mq **mq);
void		push_b_optimize(t_list *stack_a, t_list *stack_b, t_mq *mq);
void		push_a_optimize(t_list *stack_a, t_list *stack_b, t_mq *mq);

int			get_index(t_list *stack, int elem);
int			get_min(t_list *stack);
int			get_max(t_list *stack);
int			get_pos_to_place(t_list *stack, int elem);

int			new_element(int nbr, t_list **elem);
void		free_everything(t_list **stack_a, t_list **stack_b, t_mq **mq);
int			add_to_list(t_list **stack, int nbr);
void		free_stack(t_list **stack);
int			len(t_list *stack);

void		quick_sort(int array[], int low, int high);
void		get_median_quartil(char **spl, t_mq **mq, int *error);

void		push_a(t_list **stack_a, t_list **stack_b, t_mq **mq);
void		push_b(t_list **stack_a, t_list **stack_b, t_mq **mq);
void		reverse_rotate_a(t_list **stack_a, int print);
void		reverse_rotate_b(t_list **stack_b, int print);
void		reverse_rotate_both(t_list **s_a, t_list **s_b);
void		rotate_a(t_list **stack_a, int print);
void		rotate_b(t_list **stack_b, int print);
void		rotate_both(t_list **s_a, t_list **s_b);
void		swap_a(t_list **stack_a, int print);
void		swap_b(t_list **stack_b, int print);
void		swap_both(t_list **stack_a, t_list **stack_b);

void		fill_mq(t_mq **mq, int len, int array[]);
void		sort_three(t_list **stack_a);

#endif
