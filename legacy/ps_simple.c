/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 12:37:32 by legomez           #+#    #+#             */
/*   Updated: 2026/11/03 09:45:22 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

int	aprox_sqrt(int n)
{
	long	stimate;
	long	prev;
	long	r1;
	long	r2;

	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);
	stimate = n / 2;
	prev = 0;
	while (stimate < prev || prev == 0)
	{
		prev = stimate;
		stimate = (stimate + (n / stimate)) / 2;
	}
	r1 = prev;
	r2 = prev - 1;
	if ((n - (r2 * r2)) < ((r1 * r1) - n))
		return ((int)r2);
	return ((int)r1);
}
