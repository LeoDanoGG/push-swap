/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 12:49:26 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/12 11:19:45 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	adaptative(t_stack *a, t_stack *b);

static size_t	total_ops(t_stack *a, t_stack *b)
{
	int		i;
	size_t	total;

	total = 0;
	i = 0;
	while (i < 7)
	{
		total += a->ops[i];
		total += b->ops[i];
		i ++;
	}
	return (total);
}

static void	bench(t_stack *a, t_stack *b)
{
	int			disorder;
	int			mode;
	const char	symbols[3][20] = {"O(n²)", "O(n√n)", "O(n log n)"};

	disorder = compute_disorder(a);
	mode = adaptative(a, b);
	ft_printferr("[bench] disorder: %d.%d%%\n", disorder / 100, disorder % 100);
	ft_printferr("[bench] strategy: Adaptative / %s\n", symbols[mode -1]);
	ft_printferr("[bench] total_ops: %d\n", total_ops(a, b));
	ft_printferr("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		a->ops[0], b->ops[0], a->ops[4], a->ops[1], a->ops[1]);
	ft_printferr("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		a->ops[2], b->ops[2], a->ops[5], a->ops[3], b->ops[3], a->ops[6]);
}

int	run_mode(int mode, t_stack *a, t_stack *b)
{
	if (mode == 0)
		return (ft_radix_lsd(a, b), 3);
	if (mode == 1)
		return (ft_insertion_sort(a, b), 1);
	if (mode == 2)
		return (2);	//Medium algorithm
	if (mode == 3)
		return (ft_radix_lsd(a, b), 3);
	if (mode == 4)
		return (adaptative(a, b));
	if (mode == 5)
		bench(a, b);
	return (-1);
}

static int	adaptative(t_stack *a, t_stack *b)
{
	int	disorder;

	disorder = compute_disorder(a);
	if (disorder < 2000)
		return (run_mode(1, a, b));
	if (disorder >= 2000 && disorder < 5000)
		return (run_mode(2, a, b));
	if (disorder >= 5000)
		return (run_mode(3, a, b));
	return (-1);
}
