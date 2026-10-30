/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 12:56:47 by legomez           #+#    #+#             */
/*   Updated: 2026/10/30 12:56:48 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

static void	print_stack(char *label, t_arr *s)
{
	int	i;

	ft_putstr_fd(label, 1);
	i = 0;
	while (i < s->count)
	{
		ft_putnbr_fd(arr_indx(s, i), 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

void	print_stacks(t_arr *a, t_arr *b)
{
	print_stack("a: ", a);
	print_stack("b: ", b);
}

int	is_sorted(t_arr *a)
{
	int	i;

	i = 0;
	while (i < a->count - 1)
	{
		if (arr_indx(a, i) > arr_indx(a, i + 1))
			return (0);
		i++;
	}
	return (1);
}

int	exec_op(const char *op, t_arr *a, t_arr *b)
{
	if (!ft_strncmp(op, "sa", 3))
		swap(a);
	else if (!ft_strncmp(op, "sb", 3))
		swap(b);
	else if (!ft_strncmp(op, "ss", 3))
		return (swap(a), swap(b), 1);
	else if (!ft_strncmp(op, "pa", 3))
		push(b, a);
	else if (!ft_strncmp(op, "pb", 3))
		push(a, b);
	else if (!ft_strncmp(op, "ra", 3))
		rotate(a);
	else if (!ft_strncmp(op, "rb", 3))
		rotate(b);
	else if (!ft_strncmp(op, "rr", 3))
		return (rotate(a), rotate(b), 1);
	else if (!ft_strncmp(op, "rra", 4))
		reverse_rotate(a);
	else if (!ft_strncmp(op, "rrb", 4))
		reverse_rotate(b);
	else if (!ft_strncmp(op, "rrr", 4))
		return (reverse_rotate(a), reverse_rotate(b), 1);
	else
		return (0);
	return (1);
}

int	read_line(char *buf, int max)
{
	int		i;
	int		r;
	char	c;

	i = 0;
	r = read(0, &c, 1);
	while (r == 1 && c != '\n')
	{
		if (i < max - 1)
			buf[i++] = c;
		r = read(0, &c, 1);
	}
	buf[i] = '\0';
	if (r <= 0 && i == 0)
		return (-1);
	return (i);
}
