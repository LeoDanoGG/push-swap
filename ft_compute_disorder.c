/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute_disorder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtomas-m <gtomas-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 09:53:05 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/19 13:59:16 by gtomas-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Compute the amount of "mistakes" when comparing 2 numbers to see disorder
int	compute_disorder(t_stack *a)
{
	float			mistakes;
	float			total_pairs;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	if (a->size < 2)
		return (0);
	while (i < a->size)
	{
		j = i +1;
		while (j < a->size)
		{
			total_pairs += 1;
			if (ft_node_at(a, i)->val > ft_node_at(a, j)->val)
				mistakes += 1;
			j ++;
		}
		i ++;
	}
	return ((mistakes / total_pairs) * 10000);
}
