/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtomas-m <gtomas-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:36:52 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/19 13:59:10 by gtomas-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Double swap helper for checker
static void	double_swap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

//Double rotate helper for checker
static void	double_rotate(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

//Double reverse rotate helper for checker
static void	double_reverse(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

//Perform the operation passed by string return 0 on error
static int	perform_operation(char *op, t_stack *a, t_stack *b)
{
	op = checker_parse(op);
	if (ft_strncmp(op, "pa\n", 3) == 0)
		return (push(b, a), 1);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		return (push(a, b), 1);
	else if (ft_strncmp(op, "sa\n", 3) == 0)
		return (swap(a), 1);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		return (swap(b), 1);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		return (double_swap(a, b), 1);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		return (rotate(a), 1);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		return (rotate(b), 1);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		return (double_rotate(a, b), 1);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		return (reverse_rotate(a), 1);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		return (reverse_rotate(b), 1);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		return (double_reverse(a, b), 1);
	return (0);
}

//Checker entry point. Read from stdin, if error free and return
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	if (argc == 1)
		return (0);
	a = valid_input(argc -1, argv +1);
	b = ft_calloc(1, sizeof(t_stack));
	if (!a || !b)
		return (error(a, b));
	line = get_next_line(0);
	while (line)
	{
		if (!perform_operation(line, a, b))
			return (free(line), error(a, b));
		free(line);
		line = get_next_line(0);
	}
	if (compute_disorder(a) == 0 && b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_stack_clear(a);
	ft_stack_clear(b);
	return (0);
}
