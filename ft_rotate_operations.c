/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:28:55 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/18 11:33:17 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	rotate(a);
	a->ops[2]++;
	print_str("ra\n");
}

void	rb(t_stack *b)
{
	rotate(b);
	b->ops[2]++;
	print_str("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	a->ops[5]++;
	print_str("rr\n");
}

//Move up all the numbers of arr making the first number last
void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*next;

	if (!stack || stack->size < 2)
		return ;
	last = ft_node_last(stack);
	first = stack->head;
	next = first ->next;
	last->next = first;
	first->next = NULL;
	stack->head = next;
}
