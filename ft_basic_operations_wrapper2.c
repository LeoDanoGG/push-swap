/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_operations_wrapper2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtomas-m <gtomas-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:28:55 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/10 16:16:04 by gtomas-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *b)
{
	rotate(b);
	b->ops[2]++;
	print_str("rb\n");
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	a->ops[3]++;
	print_str("rra\n");
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	b->ops[3]++;
	print_str("rrb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	a->ops[4]++;
	print_str("ss\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	a->ops[5]++;
	print_str("rr\n");
}
