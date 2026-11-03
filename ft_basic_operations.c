/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 17:43:16 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/03 15:38:11 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

//Remove the first number of src and add it into the top of dest
void	push(t_stack *src, t_stack *dest)
{
	t_node	*src_head;

	if (!src || src->size < 1)
		return ;
	src_head = src->head;
	src->head = src->head->next;
	src_head->next = dest->head;
	dest->head = src_head;
	dest->size ++;
	src->size --;
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

//Move down all the numbers of arr making the last number first
void	reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || stack->size < 2)
		return ;
	last = stack->head;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stack->head;
	stack->head = last;
}
