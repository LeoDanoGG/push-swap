/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 12:56:44 by legomez           #+#    #+#             */
/*   Updated: 2026/10/30 19:21:24 by legomez          ###   ########.fr       */
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
	k = (int)(1.3f * aprox_sqrt(a->count));

	while (a->count != 0)
	{
		ft_printf("Count: %d | K: %d\n", count, k);
		show(a, b);
		if (a->start <= count)
		{
			push(a, b);
			rotate(b);
			count++;
		}
		else if (a->start <= count + k)
		{
			push(a, b);
			count++;
		}
		else
			rotate(a);
		sleep(1);
	}
}

// {	"one",		{42},								LEN(one)	}
// {	"sorted",	{1, 2, 3, 4, 5},					LEN(sorted)	}
// {	"five",		{3, 5, 1, 4, 2},					LEN(five)	}
// {	"ten",		{7, 2, 9, 1, 5, 10, 3, 8, 6, 4},	LEN(ten)	}
// {	"neg",		{-3, 5, 0, -10, 8, 2},				LEN(neg)	}