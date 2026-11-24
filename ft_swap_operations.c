/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 17:43:16 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/19 12:03:07 by legomez          ###   ########.fr       */
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

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	a->ops[4]++;
	print_str("ss\n");
}

//Swap the first to nodes of stack
void	swap(t_stack *stack)
{
	t_node	*a;
	t_node	*b;

	if (!stack || stack->size < 2)
		return ;
	a = stack->head;
	b = a->next;
	a->next = b->next;
	b->next = a;
	stack->head = b;
}
