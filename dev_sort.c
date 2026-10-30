/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 12:56:44 by legomez           #+#    #+#             */
/*   Updated: 2026/10/30 18:30:56 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

int	aprox_sqrt(int x)
{
	long	stimate;
	long	prev;
	long	r1;
	long	r2;

	if (x < 0)
		return (-1);
	if (x == 0 || x == 1)
		return (x);
	stimate = x / 2;
	prev = 0;
	while (stimate < prev || prev == 0)
	{
		prev = stimate;
		stimate = (stimate + (x / stimate)) / 2;
	}
	r1 = prev;
	r2 = prev - 1;
	if ((x - (r2 * r2)) < ((r1 * r1) - x))
		return ((int)r2);
	return ((int)r1);
}

// Algorithm
void	dev_sort(t_arr *a, t_arr *b)
{
	int	k;
	int	count;

	count = 0;
	k = (1.3f * aprox_sqrt(10));
	while (a->size != 0)
	{
		ft_printf("Count: %d\n", count, k);
		show(a, b);
		if (a->arr[0] <= count)
		{
			push(a, b);
			rotate(b);
		}
		else if (a->arr[0] <= count + k)
			push(b, a);
		else
			rotate(a);
		count++;
		sleep(1);
	}
}

	// if (is_sorted(a) && !b->count)
	// 	ft_printf("OK\n");
	// else
	// 	ft_printf("KO\n");