/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 12:56:44 by legomez           #+#    #+#             */
/*   Updated: 2026/11/03 09:53:28 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

void	index_stack(t_arr *a)
{
	int	*rank;
	int	i;
	int	j;

	rank = ft_calloc(a->count, sizeof(int));
	if (!rank)
		return ;
	i = -1;
	while (++i < a->count)
	{
		j = -1;
		while (++j < a->count)
			if (arr_indx(a, j) < arr_indx(a, i))
				rank[i]++;
	}
	i = -1;
	while (++i < a->count)
		a->arr[(a->start + i) % a->size] = rank[i];
	free(rank);
}

static int	max_pos(t_arr *b)
{
	int	i;
	int	pos;

	pos = 0;
	i = 1;
	while (i < b->count)
	{
		if (arr_indx(b, i) > arr_indx(b, pos))
			pos = i;
		i++;
	}
	return (pos);
}

static void	push_chunks(t_arr *a, t_arr *b, int k)
{
	int	count;

	count = 0;
	while (a->count != 0)
	{
		show(a, b);
		if (arr_indx(a, 0) <= count)
		{
			push(a, b);
			rotate(b);
			count++;
		}
		else if (arr_indx(a, 0) <= count + k)
		{
			push(a, b);
			count++;
		}
		else
			rotate(a);
	}
}

static void	push_back(t_arr *a, t_arr *b)
{
	int	pos;

	while (b->count != 0)
	{
		pos = max_pos(b);
		if (pos <= b->count / 2)
		{
			while (pos-- > 0)
				rotate(b);
		}
		else
		{
			while (pos++ < b->count)
				reverse_rotate(b);
		}
		push(b, a);
	}
}

void	dev_sort(t_arr *a, t_arr *b)
{
	index_stack(a);
	push_chunks(a, b, (int)(1.3f * aprox_sqrt(a->count)));
	push_back(a, b);
}
