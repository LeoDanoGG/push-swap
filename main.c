/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtomas-m <gtomas-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:47:04 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/19 14:01:44 by gtomas-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Check what mode is passed as option else return -1 (no specific mode)
static int	check_mode(char *mode)
{
	if (!mode)
		return (-1);
	if (ft_strncmp(mode, "--adaptative", 13) == 0)
		return (0);
	else if (ft_strncmp(mode, "--simple", 9) == 0)
		return (1);
	else if (ft_strncmp(mode, "--medium", 9) == 0)
		return (2);
	else if (ft_strncmp(mode, "--complex", 10) == 0)
		return (3);
	return (-1);
}

//Execute the algorithm and print bench mode if desired
static void	execute_algorithms(t_stack *a, t_stack *b, int mode, int bench_mode)
{
	int	disorder;

	if (!a || !b)
	{
		error(a, b);
		return ;
	}
	ft_stack_normailze(a);
	disorder = compute_disorder(a);
	if (mode == -1)
		mode = 0;
	mode = run_mode(mode, a, b);
	if (bench_mode)
		bench(mode, disorder, a, b);
	ft_stack_clear(a);
	ft_stack_clear(b);
}

//Main entry for push_swap, check argv and execute desired algorithm
int	main(int argc, char **argv)
{
	int		mode;
	int		bench_mode;
	int		args_start;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	args_start = 1;
	bench_mode = 0;
	mode = 0;
	if (ft_strncmp(argv[args_start], "--bench", 8) == 0)
	{
		bench_mode = 1;
		args_start++;
	}
	mode = check_mode(argv[args_start]);
	if (mode != -1)
		args_start++;
	if (args_start >= argc)
		return (0);
	a = valid_input(argc - args_start, argv + args_start);
	b = ft_calloc(1, sizeof(t_stack));
	execute_algorithms(a, b, mode, bench_mode);
	return (0);
}
