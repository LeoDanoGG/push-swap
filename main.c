/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:47:04 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/12 13:28:20 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error(t_stack *a, t_stack *b)
{
	ft_stack_clear(a);
	free(a);
	ft_stack_clear(b);
	free(b);
	ft_putstr_fd("Error\n", 1);
	return (-1);
}

int	check_mode(char *mode)
{
	size_t	len;

	len = ft_strlen(mode);
	if (ft_strncmp(mode, "--simple", len) == 0)
		return (1);
	if (ft_strncmp(mode, "--medium", len) == 0)
		return (2);
	if (ft_strncmp(mode, "--complex", len) == 0)
		return (3);
	if (ft_strncmp(mode, "--adaptative", len) == 0)
		return (4);
	if (ft_strncmp(mode, "--bench", len) == 0)
		return (5);
	return (0);
}

int	main(int argc, char **argv)
{
	int		mode;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	mode = check_mode(argv[1]);
	if (mode != 0)
		a = valid_input(argc -2, argv +2);
	else
		a = valid_input(argc -1, argv +1);
	b = ft_calloc(1, sizeof(t_stack));
	if (!a || !b)
		return (error(a, b));
	ft_stack_normailze(a);
	run_mode(mode, a, b);
	ft_stack_clear(a);
	ft_stack_clear(b);
	free(a);
	free(b);
	return (0);
}
