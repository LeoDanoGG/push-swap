/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_lsd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtomas-m <gtomas-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:05:24 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/10 17:55:56 by gtomas-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_idx(t_stack *a)
{
	int		current_largest;
	t_node	*curr;
	int		max;

	max = 0;
	curr = a->head;
	current_largest = curr->norm_val;
	while (curr)
	{
		if (curr->norm_val > current_largest)
			current_largest = curr->norm_val;
		curr = curr->next;
	}
	while ((current_largest >> max) != 0)
		max++;
	return (max);
}

int	get_bit_at(int num, int idx)
{
	return ((num >> idx) & 1);
}

void	ft_radix_lsd(t_stack *a, t_stack *b)
{
	int	max;
	int	idx;
	int	i;
	int	size;

	max = max_idx(a);
	idx = 0;
	if (compute_disorder(a) == 0)
		return ;
	while (idx < max)
	{
		size = a->size;
		i = 0;
		while (i < size)
		{
			if (get_bit_at(a->head->norm_val, idx) == 1)
				ra(a);
			else
				pb(b, a);
			i++;
		}
		while (b->size > 0)
			pa(a, b);
		idx++;
	}
}
