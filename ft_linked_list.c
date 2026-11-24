/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtomas-m <gtomas-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:08:05 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/19 13:59:45 by gtomas-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Create a new node
t_node	*ft_nodenew(int val, int norm)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->val = val;
	node->norm_val = norm;
	node->next = NULL;
	return (node);
}

//Add a node at the end of stack
void	ft_node_addback(t_stack *stack, t_node *new)
{
	t_node	*last;

	if (!stack || !new)
		return ;
	last = ft_node_last(stack);
	if (!last)
		stack->head = new;
	else
		last->next = new;
	stack->size++;
}

//Add a node at the front of stack
void	ft_node_addfront(t_stack *stack, t_node *new)
{
	if (!stack || !new)
		return ;
	new->next = stack->head;
	stack->head = new;
	stack->size++;
}

//Return the last node of stack
t_node	*ft_node_last(t_stack *stack)
{
	t_node	*head;

	if (!stack || !stack->head)
		return (NULL);
	head = stack->head;
	while (head->next)
		head = head->next;
	return (head);
}
