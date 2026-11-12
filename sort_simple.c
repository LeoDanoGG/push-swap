/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 11:36:56 by legomez           #+#    #+#             */
/*   Updated: 2026/11/12 14:36:01 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_idx(t_stack *b)
{
	t_node	*curr;
	int		pos;
	int		best_idx;
	int		best_val;

	pos = 0;
	best_idx = 0;
	best_val = b->head->norm_val;
	curr = b->head;
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

static int	find_insert_idx(t_stack *b, int val)
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

static void	bring_to_top(t_stack *b, int idx)
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

void	ft_insertion_sort(t_stack *a, t_stack *b)
{
	int	idx;

	idx = 0;
	if (a->size < 2)
		return ;
	while (a->size > 0)
	{
		idx = find_insert_idx(b, a->head->norm_val);
		bring_to_top(b, idx);
		pb(b, a);
	}
	bring_to_top(b, find_max_idx(b));
	while (b->size > 0)
		pa(a, b);
}

//  shuf -i 0-99 -n 500 > args.txt && ccflags *.c */*.c && ./a.out --simple $(cat args.txt) | wc -l >> result.txt