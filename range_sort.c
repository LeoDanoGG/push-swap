/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtomas-m <gtomas-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:47:36 by legomez           #+#    #+#             */
/*   Updated: 2026/11/19 14:02:30 by gtomas-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bit_at(int num, int idx);

/* find the stimated sqrt for stack size */
static int	find_sqrt(long n)
{
	int	r;

	r = 0;
	while ((r + 1) * (r + 1) <= n)
		r++;
	return (r);
}

//Push b stack into a stack
static void	range_push_b(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		bring_to_top(b, find_max_idx(b));
		pa(a, b);
	}
}

void	ft_range_sort(t_stack *a, t_stack *b)
{
	int	range;
	int	pushed;

	pushed = 0;
	if (compute_disorder(a) == 0 || a->size < 2)
		return ;
	range = (int)(find_sqrt(a->size) * 1.3);
	while (a->size > 0)
	{
		if (a->head->norm_val <= pushed)
		{
			pb(b, a);
			if (b->size > 1)
				rb(b);
		}
		else if (a->head->norm_val <= (pushed + range))
			pb(b, a);
		else
			ra(a);
		pushed = (int)b->size;
	}
	range_push_b(a, b);
}
