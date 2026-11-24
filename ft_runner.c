/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtomas-m <gtomas-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 12:49:26 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/19 14:01:06 by gtomas-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	adaptative(t_stack *a, t_stack *b);

//Return the total amount of ops done
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

//Print the bench mode result
void	bench(int mode, int disorder, t_stack *a, t_stack *b)
{
	const char	symbols[3][20] = {"O(n²)", "O(n√n)", "O(n log n)"};
	const char	complx[4][20] = {"Adaptative", "Simple", "Medium", "Complex"};
	int			symbol;

	symbol = mode -1;
	if (mode == 0)
	{
		if (disorder >= 2000 && disorder < 5000)
			symbol = 1;
		else if (disorder >= 5000)
			symbol = 2;
		else
			symbol = 0;
	}
	ft_printferr("[bench] disorder: %d.%d%%\n", disorder / 100, disorder % 100);
	ft_printferr("[bench] strategy: %s / %s\n", complx[mode], symbols[symbol]);
	ft_printferr("[bench] total_ops: %d\n", total_ops(a, b));
	ft_printferr("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		a->ops[0], b->ops[0], a->ops[4], a->ops[1], a->ops[1]);
	ft_printferr("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		a->ops[2], b->ops[2], a->ops[5], a->ops[3], b->ops[3], a->ops[6]);
}

//Execute the algorithms based on mode
int	run_mode(int mode, t_stack *a, t_stack *b)
{
	if (a->size < 16)
		return (small_sort(a, b), mode);
	if (mode == 1)
		return (ft_turk_sort(a, b), 1);
	if (mode == 2)
		return (ft_range_sort(a, b), 2);
	if (mode == 3)
		return (ft_radix_lsd(a, b), 3);
	return (adaptative(a, b), 0);
}

//Get the mode if adaptative
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
