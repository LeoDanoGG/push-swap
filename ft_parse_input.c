/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtomas-m <gtomas-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 12:33:33 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/10 17:55:57 by gtomas-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if stack has duplicates
static int	has_dups(t_stack *stack)
{
	t_node	*curr;
	t_node	*curr_2;

	curr = stack->head;
	while (curr)
	{
		curr_2 = curr->next;
		while (curr_2)
		{
			if (curr_2->val == curr->val)
				return (1);
			curr_2 = curr_2->next;
		}
		curr = curr->next;
	}
	return (0);
}

// Check if string has only digits
static int	only_digits(char *s)
{
	int	i;

	i = 0;
	if ((s[0] == '-' || s[0] == '+') && ft_strlen(s) > 1)
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

// Free Splitted and stack
static int	free_all(char **splitted, t_stack *stack)
{
	int	i;

	i = 0;
	ft_stack_clear(stack);
	free(stack);
	if (!splitted)
		return (0);
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (0);
}

static int	add_if_valid(char **splitted, t_stack *stack)
{
	t_node	*new;
	int		j;

	j = 0;
	while (splitted[j])
	{
		if (!only_digits(splitted[j]))
			return (free_all(splitted, stack));
		new = ft_nodenew(ft_atoi(splitted[j]), 0);
		if (!new)
			return (free_all(splitted, stack));
		ft_node_addback(stack, new);
		if (has_dups(stack))
			return (free_all(splitted, stack));
		j++;
	}
	j = 0;
	while (splitted[j])
	{
		free(splitted[j]);
		j ++;
	}
	free(splitted);
	return (1);
}

// If input insn't valid return NULL else return a new stack filled with input
t_stack	*valid_input(int argc, char **argv)
{
	char	**splitted;
	int		i;
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		splitted = ft_split(argv[i], ' ');
		if (!splitted)
			return (ft_stack_clear(stack), free(stack), NULL);
		if (!add_if_valid(splitted, stack))
			return (NULL);
		i++;
	}
	return (stack);
}
