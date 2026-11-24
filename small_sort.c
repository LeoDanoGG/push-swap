/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtomas-m <gtomas-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:28:08 by legomez           #+#    #+#             */
/*   Updated: 2026/11/19 14:02:29 by gtomas-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_idx(t_stack *s)
{
	t_node	*curr;
	int		pos;
	int		best_idx;
	int		best_val;

	pos = 0;
	best_idx = 0;
	best_val = s->head->norm_val;
	curr = s->head;
	while (curr)
	{
		if (curr->norm_val < best_val)
		{
			best_val = curr->norm_val;
			best_idx = pos;
		}
		curr = curr->next;
		pos++;
	}
	return (best_idx);
}

static void	sort_three(t_stack *a)
{
	int	max_pos;

	if (compute_disorder(a) == 0)
		return ;
	max_pos = find_max_idx(a);
	if (max_pos == 0)
		ra(a);
	else if (max_pos == 1)
		rra(a);
	max_pos = find_max_idx(a);
	if (a->head->norm_val > a->head->next->norm_val)
		sa(a);
}

//Optimal sort for small amount of numbers
void	small_sort(t_stack *a, t_stack *b)
{
	int	min_pos;

	if (compute_disorder(a) == 0)
		return ;
	while (a->size > 3)
	{
		min_pos = find_min_idx(a);
		rotate_a(a, signed_cost((int)a->size, min_pos));
		pb(b, a);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
