/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 11:36:56 by legomez           #+#    #+#             */
/*   Updated: 2026/11/03 16:16:43 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubble_sort(t_stack *stack)
{
	t_node	*curr;
	t_node	*next;

	if (!stack || stack->size < 2)
		return ;
	curr = stack->head;
	while (curr)
	{
		show_stack(stack, 'a');
		next = curr->next;
		while (next)
		{
			if (curr->val > next->val)
				swap(stack);
			next = next->next;
		}
		curr = curr->next;
	}
}
