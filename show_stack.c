/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:32:03 by legomez           #+#    #+#             */
/*   Updated: 2026/11/03 15:35:31 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
