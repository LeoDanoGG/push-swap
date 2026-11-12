/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_operations_wrapper1.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtomas-m <gtomas-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:28:55 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/10 16:15:46 by gtomas-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	swap(a);
	a->ops[0]++;
	print_str("sa\n");
}

void	sb(t_stack *b)
{
	swap(b);
	b->ops[0]++;
	print_str("sb\n");
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	a->ops[1]++;
	print_str("pa\n");
}

void	pb(t_stack *b, t_stack *a)
{
	push(a, b);
	b->ops[1]++;
	print_str("pb\n");
}

void	ra(t_stack *a)
{
	rotate(a);
	a->ops[2]++;
	print_str("ra\n");
}
