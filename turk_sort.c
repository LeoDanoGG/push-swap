/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtomas-m <gtomas-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 11:36:56 by legomez           #+#    #+#             */
/*   Updated: 2026/11/19 14:02:23 by gtomas-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	signed_cost(int size, int idx)
{
	if (idx <= size / 2)
		return (idx);
	return ((size - idx) * -1);
}

int	find_max_idx(t_stack *s)
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
		if (curr->norm_val > best_val)
		{
			best_val = curr->norm_val;
			best_idx = pos;
		}
		curr = curr->next;
		pos++;
	}
	return (best_idx);
}

int	find_insert_idx(t_stack *b, int val)
{
	t_node	*prev;
	t_node	*curr;
	int		pos;

	if (b->size < 2)
		return (0);
	prev = ft_node_last(b);
	curr = b->head;
	pos = 0;
	while (curr)
	{
		if (prev->norm_val > val && val > curr->norm_val)
			return (pos);
		prev = curr;
		curr = curr->next;
		pos++;
	}
	return (find_max_idx(b));
}

void	bring_to_top(t_stack *b, int idx)
{
	int	pos;

	pos = ((int)b->size - idx);
	if (idx <= (int)b->size / 2)
	{
		while (idx)
		{
			rb(b);
			idx--;
		}
	}
	else
	{
		while (pos)
		{
			rrb(b);
			pos--;
		}
	}
}

//Set desired idx of b to the top by efficient rotations
void	ft_turk_sort(t_stack *a, t_stack *b)
{
	t_cost	c;

	if (compute_disorder(a) == 0 || a->size < 2)
		return ;
	while (a->size > 0)
	{
		c = find_cheapest(a, b);
		rotate_both(a, b, &c);
		rotate_a(a, c.ca);
		rotate_b(b, c.cb);
		pb(b, a);
	}
	bring_to_top(b, find_max_idx(b));
	while (b->size > 0)
		pa(a, b);
}
