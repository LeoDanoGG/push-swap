/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtomas-m <gtomas-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 11:36:56 by legomez           #+#    #+#             */
/*   Updated: 2026/11/19 14:02:28 by gtomas-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	total_cost(int ca, int cb)
{
	if (ca >= 0 && cb >= 0)
	{
		if (ca > cb)
			return (ca);
		else
			return (cb);
	}
	else if (ca < 0 && cb < 0)
	{
		if (ca < cb)
			return (ca * -1);
		else
			return (cb * -1);
	}
	if ((ca - cb) < 0)
		return ((ca - cb) * -1);
	else
		return (ca - cb);
}

//Return the cost of the chepest operations
t_cost	find_cheapest(t_stack *a, t_stack *b)
{
	t_cost	best;
	t_cost	cost;
	int		best_total;
	t_node	*curr;
	int		pos;

	best.ca = 0;
	best.cb = 0;
	best_total = -1;
	curr = a->head;
	pos = 0;
	while (curr)
	{
		cost.ca = signed_cost((int)a->size, pos);
		cost.cb = signed_cost((int)b->size,
				find_insert_idx(b, curr->norm_val));
		if (best_total == -1 || total_cost(cost.ca, cost.cb) < best_total)
		{
			best = cost;
			best_total = total_cost(cost.ca, cost.cb);
		}
		curr = curr->next;
		pos++;
	}
	return (best);
}

void	rotate_both(t_stack *a, t_stack *b, t_cost *c)
{
	while (c->ca > 0 && c->cb > 0)
	{
		rr(a, b);
		c->ca--;
		c->cb--;
	}
	while (c->ca < 0 && c->cb < 0)
	{
		rrr(a, b);
		c->ca++;
		c->cb++;
	}
}

void	rotate_a(t_stack *a, int ca)
{
	while (ca > 0)
	{
		ra(a);
		ca--;
	}
	while (ca < 0)
	{
		rra(a);
		ca++;
	}
}

void	rotate_b(t_stack *b, int cb)
{
	while (cb > 0)
	{
		rb(b);
		cb--;
	}
	while (cb < 0)
	{
		rrb(b);
		cb++;
	}
}
