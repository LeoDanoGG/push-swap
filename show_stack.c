/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:32:03 by legomez           #+#    #+#             */
/*   Updated: 2026/11/04 12:27:18 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Prints the stack values */
void	show_stack(t_stack *stack, char name)
{
	t_node	*curr;

	curr = stack->head;
	ft_printf("%c: ", name);
	while (curr)
	{
		ft_printf("%d ", curr->val);
		curr = curr->next;
	}
	ft_printf("\n");
}

/* Checks if the stacks are in the correct order */
void	check_order(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size != 0)
		return ;
	show_stack(stack_a, 'a');
	show_stack(stack_b, 'b');
	if (compute_disorder(stack_a) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
