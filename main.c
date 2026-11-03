/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 11:43:40 by legomez           #+#    #+#             */
/*   Updated: 2026/11/03 15:43:45 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = valid_input(argc, argv);
	if (!a)
		return (write(2, "Error\n", 6), 1);
	b = ft_calloc(1, sizeof(t_stack));
	if (!b)
	{
		ft_stack_clear(a);
		free(a);
		return (write(2, "Error\n", 6), 1);
	}
	ft_stack_normailze(a);
	ft_bubble_sort(a);
	ft_stack_clear(a);
	ft_stack_clear(b);
	free(a);
	free(b);
	return (0);
}
