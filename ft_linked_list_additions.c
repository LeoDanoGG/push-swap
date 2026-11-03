/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list_additions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtomas-m <gtomas-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:40:42 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/03 12:52:18 by gtomas-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_clear(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->size = 0;
	stack->head = NULL;
}

void	ft_stack_normailze(t_stack *stack)
{
	t_node	*curr;
	t_node	*curr_2;
	int		rank;

	curr = stack->head;
	while (curr)
	{
		rank = 0;
		curr_2 = stack->head;
		while (curr_2)
		{
			if (curr_2->val != curr->val && curr_2->val < curr->val)
				rank++;
			curr_2 = curr_2 ->next;
		}
		curr->norm_val = rank;
		curr = curr->next;
	}
}

t_node	*ft_node_at(t_stack *stack, int idx)
{
	t_node	*curr;
	int		i;

	i = 0;
	curr = stack->head;
	while (curr->next && i < idx)
		curr = curr->next;
	return (curr);
}
