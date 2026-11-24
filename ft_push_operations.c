/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:28:55 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/18 11:55:14 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
